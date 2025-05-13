#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

void ReadCase();
void SolveCase();

int n;
string s;

int main() {
    int t;
    cin >> t;

    while(t--) {
        ReadCase();
        SolveCase();
    }

    return 0;
}

void ReadCase() {
    cin >> n >> s;
}

void SolveCase() {
    int ans = 0;

    if(s[0] == '1') ans++;

    for(int i = 0; i < n-1; i++) {
        ans += (s[i] != s[i+1]);
    }

    cout << ans << "\n";
}
