#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n; 
    cin>>n;
    int N=2*n;
    vector<int> a(N+1);
    for (int i=1;i<=N;i++) {
    	cin>>a[i];
    }
    vector<int> first(n+1,-1);
    vector<ll> dp(N+1,0);
    for (int i=1;i<=N;i++){
        dp[i]=dp[i-1]+1;
        if (first[a[i]]==-1) first[a[i]]=i;
        else {
            int l=first[a[i]];
            ll len=i-l+1;
            ll score=len*len;
            dp[i]=max(dp[i],dp[l-1]+score);
        }
    }
    cout<<dp[N]<<endl;
}
int main(){
    int t; 
    cin >> t;
    while (t--) solve();
    return 0;
}