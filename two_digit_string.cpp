#include<iostream>
#include<vector>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        int R=s1.size();
        int C=s2.size();
        vector<int> sum1(R),sum2(C);
        sum1[0]=s1[0]-'0';
        sum2[0]=s2[0]-'0';
       for(int i=1;i<R;i++){
       	sum1[i]=(sum1[i-1]+(s1[i]-'0'))%10;
       }
       for(int i=1;i<C;i++){
       	sum2[i]=(sum2[i-1]+(s2[i]-'0'))%10;
       }
       	if(sum1[R-1]!=sum2[C-1]){
       		cout<<-1<<endl;
       		continue;
       	}
       	vector<vector<int>> dp(R+1,vector<int>(C+1,0));
       	for(int row=1;row<R+1;row++){
       		for(int col=1;col<C+1;col++){
       			if(sum1[row-1]==sum2[col-1]){
       				dp[row][col]=dp[row-1][col-1]+1;
       			}
       			else{
       				dp[row][col]=max(dp[row-1][col],dp[row][col-1]);
       			}
       		}
       	}
       	cout<<dp[R][C]<<endl;
    }
}