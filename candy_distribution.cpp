#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    long long ans=0;
    map<int,int> mp;
    int modv=0;
    mp[modv]=1;
    for(int i=1;i<=N;i++){
    	int curr;
    	cin>>curr;
    	modv=(modv+curr)%M;
    	if(mp.find(modv)!=mp.end()){
    		ans+=mp[modv];
    		mp[modv]++;
    	}
    	else{
    		mp[modv]=1;
    	}
    }
    cout<<ans<<endl;
}