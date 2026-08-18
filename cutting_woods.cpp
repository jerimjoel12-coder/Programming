#include<bits/stdc++.h>
using namespace std;
int main(){
	int L;
	cin>>L;
	int q;
	cin>>q;
	set<int> st={0,L};
	while(q--){
		int c,n;
		cin>>c>>n;
		if(c==1){
			st.insert(n);
		}
		else{
			auto it=st.lower_bound(n);
			cout<<*it-*prev(it)<<endl;
		}
	}
}