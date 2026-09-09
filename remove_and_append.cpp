#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,Q;
	cin>>N>>Q;
	vector<int> pos(N+1,0);
	for(int p=1;p<=N;p++){
		int curr;cin>>curr;
		pos[curr]=p;
	}
	int nxtpos=N+1;
	while(Q--){
		int val; cin>>val;
		pos[val]=nxtpos++;
	}
	vector<pair<int,int>> arr;
	for(int val=1;val<=N;val++){
		arr.push_back(make_pair(pos[val],val));
	}
	sort(arr.begin(),arr.end());
	for(auto [pos,val]: arr){
		cout<<val<<" ";
	}
	cout<<endl;
}