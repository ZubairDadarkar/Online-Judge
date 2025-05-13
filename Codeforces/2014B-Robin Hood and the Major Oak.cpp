#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        int odd_cnt = k/2;
        if(n%2 && k%2) odd_cnt++;

        if(odd_cnt%2) cout << "NO\n";
        else cout << "YES\n";
    }
}
