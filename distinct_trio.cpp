#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<int> arr(N+1);
	for(int i=1;i<=N;i++){
		cin>>arr[i];
	}
	sort(arr.begin()+1,arr.end());
	long long ans=0;
	for(int i=1;i<=N;i++){
		int high=arr.end()-upper_bound(arr.begin()+1,arr.end(),arr[i]);
		int low=lower_bound(arr.begin()+1,arr.end(),arr[i])-(arr.begin()+1);
		ans+=1LL*high*low;	
	}
	cout<<ans;
}