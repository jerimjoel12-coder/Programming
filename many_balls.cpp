#include<bits/stdc++.h>
using namespace std;
int main(){
	long long N;
	cin>>N;
	string ans="";
	while(N!=0){
		if(N%2==1){
			ans+="A";
			N-=1;
			
		}
		else{
			ans+="B";
			N/=2;
		}
	}
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i];
	}
}