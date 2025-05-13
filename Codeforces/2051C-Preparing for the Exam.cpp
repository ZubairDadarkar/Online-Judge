#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n, m, k;
vector<int> A, B;

void ReadCase() {
    cin >> n >> m >> k;
    A.clear(); A.resize(m);
    for(int i = 0; i < m; i++) cin >> A[i];
    B.clear(); B.resize(n+1, 0);
    for(int i = 0; i < k; i++) {
        int idx; cin >> idx;
        B[idx] = 1;
    }
}

string SolveCase() {
    string ans = "";
    bool x;
    for(int v : A) {
        x = true;
        for(int i = 1; i <= n; i++) {
            if(i == v) continue;
            if(!B[i]) {
                ans += '0';
                x = false;
                break;
            }
        }
        if(x) ans += '1';
    }

    return ans;
}

int main() {
    int t; cin >> t;
    while(t--) {
        ReadCase();
        cout << SolveCase() << "\n";
    }

    return 0;
}

