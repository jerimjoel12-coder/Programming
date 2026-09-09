#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		int oddctr=0,eoq=0,eeq=0;
		for(int i=0;i<N;i++){
			int n;
			cin>>n;
			if(n%2==1){
				oddctr+=1;
			}
			else{
				int q=n/2;
				if(q%2==1){
					eoq+=1;
				}
				else{
					eeq+=1;
				}
			}
		}
		cout<<max(max(eeq,eoq),oddctr)<<endl;
	}
}