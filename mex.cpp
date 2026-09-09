#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		vector<int> arr(N),zi;
		for(int i=0;i<N;i++) {
			cin>>arr[i];
			if(arr[i]==0) zi.push_back(i);		
		}
		if(zi.size()==1){
			cout<<"No"<<endl;
			continue;
		}
		string s(N,'C');
		if(zi.size()>0){
			int fzidx=zi[0];
			s[fzidx]='B';
			for(unsigned int i=1;i<zi.size();i++){
				s[zi[i]]='A';
			}
		}
		cout<<"Yes"<<endl<<s<<endl;
	}
}