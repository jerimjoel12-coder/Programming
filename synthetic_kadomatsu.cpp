#include<bits/stdc++.h>
using namespace std;
int ans=10000000;
int N,l1,l2,l3;
void calc(vector<int>& arr,int idx,int fs,int ss,int ts,int fc,int sc,int tc){
	if(idx==N){
		if(fc==0 || sc==0 || tc==0){
			return;
		}
		int curr=(fc-1)*10+abs(l1-fs)+(sc-1)*10+abs(l2-ss)+(tc-1)*10+abs(l3-ts);
		ans=min(ans,curr);
		return;
	}
	calc(arr,idx+1,fs+arr[idx],ss,ts,fc+1,sc,tc);
	calc(arr,idx+1,fs,ss+arr[idx],ts,fc,sc+1,tc);
	calc(arr,idx+1,fs,ss,ts+arr[idx],fc,sc,tc+1);
	calc(arr,idx+1,fs,ss,ts,fc,sc,tc);
}

int main(){
	cin>>N>>l1>>l2>>l3;
	vector<int> arr(N);
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	calc(arr,0,0,0,0,0,0,0);
	cout<<ans<<endl;
}
