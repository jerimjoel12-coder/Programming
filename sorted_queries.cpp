#include<bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin>>Q;
    priority_queue<int, vector<int>, greater<int>> st;
    queue<int> q;
    while(Q--) {
        int ch;
        cin>>ch;
        if (ch==1) {
            int val;
            cin>>val;
            q.push(val);
        }else if (ch==2) {
            if (!st.empty()) {
            	cout<<st.top()<<endl;
            	st.pop();
            }else{
            	cout<<q.front()<<endl;
            	q.pop();
            }
        }else{
            while(!q.empty()) {
                st.push(q.front());
                q.pop();
            }
        }
    }
}