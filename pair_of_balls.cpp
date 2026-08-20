#include<bits/stdc++.h>
using namespace std;
queue<int> cyl[2<<17];
queue<int> colpos[2<<17];
int main(){
	int N,M;
	cin>>N>>M;
	queue<int> rq;
	for(int ci=0;ci<M;ci++){
		int k;
		cin>>k;
		while(k--){
			int a;
			cin>>a;
			cyl[ci].push(a);
		}
		int top=cyl[ci].front();
		colpos[top].push(ci);
		if(colpos[top].size()==2){
			rq.push(top);
		}
	}
	int removed=0;
	while(!rq.empty()){
		int front=rq.front();
		rq.pop();
		removed++;
		while(!colpos[front].empty()){
			int currfront=colpos[front].front();
			colpos[front].pop();
			cyl[currfront].pop();
			if(cyl[currfront].size()>0){
				int nxt=cyl[currfront].front();
				colpos[nxt].push(currfront);
				if(colpos[nxt].size()==2){
					rq.push(nxt);
				}
			}
		}
	}
	cout<<(removed==N?"Yes":"No")<<endl;
}