#include <bits/stdc++.h>
#define ll long long
#define MAX 101

using namespace std;

int n;
vector<int> M, S;

void ReadCase() {
    cin >> n;
    M.clear(); M.resize(n+1);
    S.clear(); S.resize(n+1);
    for(int i = 0; i < n; i++) cin >> M[i];
    for(int i = 0; i < n; i++) cin >> S[i];
}

int SolveCase() {
    if(n == 1) return M[0];
    int cnt_m = M[n-1], cnt_s = 0;
    for(int i = 1; i < n; i++) {
        if(M[i-1] > S[i]) {
            cnt_m += M[i-1];
            cnt_s += S[i];
        }
    }

    return abs(cnt_m - cnt_s);
}

int main() {
    int t; cin >> t;
    while(t--) {
        ReadCase();
        int ans = SolveCase();
        cout << ans << "\n";
    }

    return 0;
}

