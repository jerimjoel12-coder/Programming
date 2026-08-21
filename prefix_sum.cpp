#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,Q;
	cin>>N>>Q;
	vector<long long> psum(N+1,0LL);
	vector<long long> arr(N);
	for(int i=1;i<=N;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=N;i++){
		psum[i]=psum[i-1]+arr[i];
	}
	while(Q--){
		int lt,rt;
		cin>>lt>>rt;
		cout<<psum[rt]-psum[lt-1]<<endl;
	}
	
}