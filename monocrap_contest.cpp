#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		int zc=0;
		int oc=0;
		vector<int> arr(N);
		for(int i=0;i<N;i++){
			cin>>arr[i];
			if(arr[i]==0){
				zc++;
			}
		}
		if(zc<2){
			cout<<"-1"<<endl;
			continue;
		}
		else{
			if(arr[0]==1 ){
				oc++;
			}
			if(arr[N-1]==1){
				oc++;
			}
		}
		cout<<oc<<endl;
	}
}