#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

string s;

void ReadCase() {
    cin >> s;
}

void SolveCase() {
    int n = s.size();
    int ans = INT_MAX;
    vector<int> cnt(4, 0);

    for (int last = 0, first = 0; last < n; last++) {
        cnt[s[last] - '0']++;
        while(cnt[s[first] - '0'] > 1) {
            cnt[s[first] - '0']--;
            first++;
        }

        if(cnt[1] && cnt[2] && cnt[3])
            ans = min(ans, last-first+1);
    }

    if(ans == INT_MAX) ans = 0;
    cout << ans << endl;
}

int main() {
    int t; cin >> t;

    while(t--) {
        ReadCase();
        SolveCase();
    }

    return 0;
}

