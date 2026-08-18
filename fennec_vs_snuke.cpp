#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(int start, vector<vector<int>>&graph){
	int n = graph.size();
	vector<int>hops(n, -1);
	queue<int>q;
	hops[start] = 0;
	q.push(start);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v:graph[u]){
			if(hops[v]==-1){
				hops[v] = hops[u] + 1;
				q.push(v);
			}
		}
	}
	return hops;
}
int main(){
	int N;
	cin >> N;
	vector<vector<int>>graph(N);
	for(int i=0; i<N-1; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int>black = bfs(0, graph);
	vector<int>white = bfs(N-1, graph);
	int b = 0, w = 0;
	for(int i=0; i<N; i++){
		if(black[i]<=white[i]){
			b++;
		}
		else{
			w++;
		}
	}	
	if(b>w){
		cout << "Fennec";
	}
	else{
		cout << "Snuke";
	}
	
}