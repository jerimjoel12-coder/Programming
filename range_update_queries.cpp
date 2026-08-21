#include<bits/stdc++.h>
using namespace std;
void update(vector<long long>& seg,int node,int nl,int nr,int ql,int qr,int val){
	if(nl>qr || nr<ql){
		return;
	}
	if(nl>=ql && nr<=qr){
		seg[node]+=val;
		return;
	}
	int mid=(nl+nr)/2;
	update(seg,node*2,nl,mid,ql,qr,val);
	update(seg,node*2+1,mid+1,nr,ql,qr,val);
}
long long find(vector<long long>& seg,int node,int nl,int nr,int ql,int qr){
	if(nl>qr || nr<ql){
		return 0;
	}
	if(nl>=ql && nr<=qr){
		return seg[node];
	}
	int mid=(nl+nr)/2;
	return seg[node]+find(seg,node*2,nl,mid,ql,qr)+find(seg,node*2+1,mid+1,nr,ql,qr);
}
int main(){
	int N,Q;
	cin>>N>>Q;
	int newN=1;
	while(newN<N) newN=newN<<1;
	vector<long long> seg(newN*2,0);
	for(int i=newN;i<newN+N;i++){
		cin>>seg[i];
	}
	N=newN;
	while(Q--){
		int q,lt,rt;
		cin>>q;
		if(q==1){
			int val;
			cin>>lt>>rt>>val;
			update(seg,1,1,N,lt,rt,val);
		}
		else{
			int k;
			cin>>k;
			cout<<find(seg,1,1,N,k,k)<<endl;
		}
	}
}