#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve(){
	int N,Q; ll X;
	cin >> N >> Q >> X;
	vector<ll> psum(N);
	ll totwt=0;
	for(int i=0;i<N;i++){
		int potwt; cin >> potwt;
		totwt+=potwt;
		psum[i]=potwt+(i==0?0LL:psum[i-1]);
	}
	
	int rounds=X/totwt,cyclen=0;
	X=X%totwt;
	vector<bool> vis(N,false);
	vector<int> cntarr,rptinfo(N,0);
	ll sval=X;
	int balcnt=0,loopcnt=-1,basecnt=-1;
	int previdx=-1;
	while(1){
		auto it=lower_bound(psum.begin(),psum.end(),sval);
		if(it==psum.end()){
			sval=X-(totwt-psum[previdx]);
			balcnt=N-1-previdx;
			previdx=-1;
			continue;
		}
		cyclen++;

		int currcnt=it-psum.begin()-previdx;
		int curridx=it-psum.begin();
		cntarr.push_back(currcnt+balcnt+(rounds*N));
		if(vis[curridx]){
			//cycle found	
			basecnt=rptinfo[curridx];
			loopcnt=cyclen-rptinfo[curridx];		
			break;
		}
		//continue the search
		vis[curridx]=true;
		rptinfo[curridx]=cyclen;
		sval=X+(*it);
		previdx=curridx;
		balcnt=0;
	}
    
    
	while(Q--){
		ll k; cin >> k;
		//Here to do print ans
		if(k<=cyclen){
			cout << cntarr[k-1] << endl;
			continue;
		}
		k-=basecnt;
		int cntarrpos=k%loopcnt;
		if(cntarrpos==0) cntarrpos=loopcnt;
		cout << cntarr[basecnt+cntarrpos-1] << endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc=1;
	//cin >> tc;
	while(tc--) solve();
}
