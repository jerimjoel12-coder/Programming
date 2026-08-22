#include<bits/stdc++.h>
using namespace std;

string solve() {
    int N, M;
    cin >> N >> M;
    vector<int> b(M),a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    if (N < M*2) return "NO";
    deque<int> q(a.begin(), a.end());
    sort(q.begin(), q.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < M; i++) {
        if (q.front() > b[i]) {
            return "NO";
        }
        q.pop_front();
    }
    for (int i = M-1; i >= 0; i--) {
        if (q.back() < b[i]) {
            return "NO";
        }
        q.pop_back();
    }
    return "YES";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;;
    }
    return 0;
}