#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,T;
    cin>>N>>T;
    vector<int> w(N+2,0);
    while(T--){
    	int lt,rt;
    	cin>>lt>>rt;
    	w[lt]++;
    	w[rt+1]--;
    }
    int mini=500000000;
    for(int tu=1;tu<=N;tu++){
    	w[tu]+=w[tu-1];
    	mini=min(mini,w[tu]);
    }
    cout<<mini;
}