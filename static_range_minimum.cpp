#include<bits/stdc++.h>
using namespace std;
#define INF 2e9
int find(vector<int>& seg,int node,int nl,int nr,int ql,int qr){
	if(qr<nl || ql>nr){
		return INF;
	}
	if(nl>=ql && nr<=qr){
		return seg[node];
	}
	int mid=(nl+nr)/2;
	int ltv=find(seg,node*2,nl,mid,ql,qr);
	int rtv=find(seg,node*2+1,mid+1,nr,ql,qr);
	return min(ltv,rtv);
}
int main(){
	int N,Q;
	cin>>N>>Q;
	int newN=1;
	while(newN<N) newN=newN<<1;
	vector<int> seg(2*newN,INF);
	for(int i=newN;i<newN+N;i++){
		cin>>seg[i];
	}
	for(int i=newN-1;i>=1;i--){
		seg[i]=min(seg[i+i],seg[i+i+1]);
	}
	N=newN;
	while(Q--){
		int lt,rt;
		cin>>lt>>rt;
		cout<<find(seg,1,1,N,lt,rt)<<endl;
	}
}