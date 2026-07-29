#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long int
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> digits;
	while(n!=0){
		digits.push_back(n%10);
		n/=10;
	}
	int tenpow=1;
	vector<int> ans;
	for(int i=1;i<digits.size();i++) tenpow*=10;
	for(int i=digits.size()-1;i>=0;i--){
		int dig=digits[i];
		int push=min(dig,(int)ans.size());
		int add=max(dig-(int)ans.size(),0);
		for(int idx=0;idx<push;idx++) ans[idx]+=tenpow;
		for(int idx=0;idx<add;idx++) ans.push_back(tenpow);
		tenpow/=10;
	}
	for(int bv:ans) cout << bv << " ";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc=1;
	//cin >> tc;
	while(tc--) {
		
		solve();
	}
}