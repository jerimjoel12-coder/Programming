#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<long long> A(N),B(N);
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	for(int i=0;i<N;i++){
		cin>>B[i];
	}
	long long am=0,bm=0;
	for(int i=0;i<N;i++){
		if(A[i]>B[i]){
			am+=(A[i]-B[i]);
		}
		else if(A[i]<B[i]){
			bm+=(B[i]-A[i]);
		}
	}
	if(am==0){
		cout<<"No"<<endl;
		return 0;
	}
	long long amw=(bm/am)+2;
	vector<long long> ans;
	for(int i=0;i<N;i++){
		if(A[i]<=B[i]){
			ans.push_back(1);
		}
		else{
			ans.push_back(amw);
		}
	}
	cout<<"Yes"<<endl;
	for(long long wt:ans){
		cout<<wt<<" ";
	}
	cout<<endl;
}