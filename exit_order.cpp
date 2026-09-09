#include<bits/stdc++.h>
using namespace std;
int main(){
	 int n;cin>>n;
    for(int i=0;i<n;i++){
        int val;cin>>val;
      int x=i/10;
      if((x*10+1>val) or (x*10+10<val)){
        cout<<"No";
        return 0;
      }
    }
    cout << "Yes";
    return 0;
}