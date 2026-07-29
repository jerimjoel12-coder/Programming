#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#define ll long long int
using namespace std;

void solve(){
	int N,R; cin >> N >> R;
	vector<pair<int,pair<int,int>>> g[200001];
	for(int rd=1;rd<=R;rd++){
		int a,b,d; cin >> a >> b >> d;
		g[a].push_back(make_pair(b,make_pair(d,rd)));
		g[b].push_back(make_pair(a,make_pair(d,rd)));
	}
	priority_queue<pair<ll,int>> q;
	vector<int> rdarr(N+1,0);
	vector<ll> distarr(N+1,1e18);
	q.push(make_pair(0,1));
	while(!q.empty()){
		auto p=q.top();
		q.pop();
		ll currdist=-p.first;
		int city=p.second;
		if(currdist>distarr[city]){
			continue;
		}
		for(auto op:g[city]){
			int ocity=op.first;
			int odist=op.second.first;
			int oroad=op.second.second;
			ll newdist=currdist+odist;
			if(distarr[ocity]>newdist){
				q.push(make_pair(-newdist,ocity));
				distarr[ocity]=newdist;
				rdarr[ocity]=oroad;
			}
		}
	}
	for(int c=2;c<=N;c++){
		cout << rdarr[c] << " ";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc=1;
	//cin >> tc;
	while(tc--) {
		
		solve();
	}
}
