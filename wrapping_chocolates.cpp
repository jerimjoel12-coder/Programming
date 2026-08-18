#include<bits/stdc++.h>
using namespace std;
void get_input(vector<int>& arr, int n){
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
}
int main(){
	int N,M;
	cin>>N>>M;
	vector<int> cb(N+1),cw(N+1),bb(M+1),bw(M+1);
	get_input(cb,N);get_input(cw,N);get_input(bb,M);get_input(bw,M);
	vector<pair<int,int>> s;
	for(int i=1;i<=N;i++){
		s.push_back(make_pair(cb[i],-i));
	}
	for(int i=1;i<=M;i++){
		s.push_back(make_pair(bb[i],i));
	}
	sort(s.begin(),s.end(),greater<>());
	multiset<int> st;
	for(auto[l,idx]:s){
		if(idx>0){
			st.insert(bw[idx]);
		}
		else{
			auto it=st.lower_bound(cw[-idx]);
			if(it==st.end()){
				cout<<"No"<<endl;
				return 0;
			}
			st.erase(it);
		}
	}
	cout<<"Yes"<<endl;
}

