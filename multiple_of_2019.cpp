#include<iostream>
#include<map>
using namespace std;
int main(){
	string s;
	cin>>s;
	long ans=0;
	int rem=0,pv=1,BASE=2019;
	map<int,int> m;
	m[0]=1;
	for(int i=s.size()-1;i>=0;i--){
		rem=(rem+(s[i]-'0')*pv)%BASE;
		if(m.find(rem)!=m.end()){
			ans+=m[rem];
			m[rem]++;
		}
		else{
			m[rem]=1;
		}
		pv=(pv*10)%BASE;
	}
	cout<<ans;
}