#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;long long L;
	cin>>N>>L;
	priority_queue<long long,vector<long long>,greater<>> q;
	long long sum=0;
	for(int ctr=1;ctr<=N;ctr++){
		int curr;
		cin>>curr;
		sum+=curr;
		q.push(curr);
		
		
	}
	if(sum<L){
			q.push(L-sum);
		}
	long long ans=0LL;
	while(q.size()>1){
		long long merge=q.top();
		q.pop();
		merge+=q.top();
		q.pop();
		q.push(merge);
		
		ans+=merge;
	}
	cout<<ans<<endl;
}