#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--)
	{
	long long x,y,k;
	cin>>x>>y>>k;
	long long ans=0,ctr=0;
	while(ctr<k){
		long long rem=(y+ctr)%(x+ctr);
		if(rem==y-x) break;
		ans+=rem;
		ctr++;
	}
	if(ctr<k){
			ans+=(k-ctr)*(y-x);
		}
	cout<<ans<<endl;
	}
}