#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long int
using namespace std;
int find(vector<int>& ldr,int node){
	if(ldr[node]!=node){
		ldr[node]=find(ldr,ldr[node]);
	}
	return ldr[node];
}
void join(vector<int>& ldr,int fr,int to){
	ldr[find(ldr,fr)]=find(ldr,to);
}
void solve(){
	int N,Q; cin >> N >> Q;
	vector<int> a(N+1),ldr(N+1,0);
	for(int i=1;i<=N;i++){
		cin >> a[i];
	}
	
	map<int,int> mp;//stores the first idx (initial leader) of a value
	map<int,int> lvm;//stores the current value for the leader
	
	for(int i=1;i<=N;i++){
		if(mp.find(a[i])==mp.end()){
			mp[a[i]]=i;
			lvm[i]=a[i];		     
		}
		ldr[i]=mp[a[i]];
	}
	
	
	while(Q--){
		int qt; cin >> qt;
		if(qt==1){
			int fr,to; cin >> fr >> to;
			if(fr==to) continue;
			if(mp.find(fr)!=mp.end()){
				int frldr=find(ldr,mp[fr]);
				
				if(mp.find(to)!=mp.end()){
					int toldr=find(ldr,mp[to]);
					join(ldr,frldr,toldr);
					lvm.erase(frldr);
				}
				else{
					mp[to]=frldr;
					lvm[frldr]=to;
				}
				mp.erase(fr);
				
			}
			 
			
		}else{
			int i; cin >> i;
			int idxldr=find(ldr,i);
			cout << lvm[idxldr] << endl;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc=1,ctr=1;
	cin >> tc;
	while(tc--) {
		cout << "Case "<<ctr++<<":" << endl;
		solve();
	}
}