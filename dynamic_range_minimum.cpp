#include<bits/stdc++.h>
using namespace std;
#define INF 2e9
void update(vector<int>& seg,int idx, int left, int right, int k, int val) {
    if (left == right) {
        seg[idx] = val;
    }
    else {
        int mid = left + (right - left) / 2;
        if (k <= mid) update(seg,idx*2, left, mid, k, val);
        else update(seg,idx*2+1, mid+1, right, k ,val);
        seg[idx] = min(seg[idx*2], seg[idx*2+1]);
    }
}
int find(vector<int>& seg,int node,int nl,int nr,int ql,int qr){
	if(qr<nl || ql>nr){
		return INF;
	}
	if(nr<=qr && nl>=ql){
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
	while(N>newN) newN=newN<<1;
	vector<int> seg(2*newN,INF);
	for(int i=newN;i<newN+N;i++){
		cin>>seg[i];
	}
	for(int i=newN-1;i>=1;i--){
		seg[i]=min(seg[i+i],seg[i+i+1]);
	}
	N=newN;
	while(Q--){
		int q,lt,rt,k,val;
		cin>>q;
		if(q==2){
			cin>>lt>>rt;
			cout<<find(seg,1,1,N,lt,rt)<<endl;
		}	
		else{
			cin>>k>>val;
			update(seg,1,1,N,k,val);
		}
	}
}