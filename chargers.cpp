#include<bits/stdc++.h>
using namespace std;
int main(){
	int Q,V;
	cin>>Q>>V;
	priority_queue<int> pq;
	while(Q--){
		int q,t,v;
		cin>>q>>t;
		if(q==1){
			cin>>v;
			pq.push(v-t);
		}
		else{
			if(pq.empty()) cout<<"-1"<<endl;
			else{
				cout<<min(V,pq.top()+t)<<endl;
				pq.pop();
			}
		}
	}
}