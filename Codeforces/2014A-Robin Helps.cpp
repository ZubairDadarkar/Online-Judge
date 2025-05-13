#include <bits/stdc++.h>
#define ll long long
#define MAX 102

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;

        int gold_cnt = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            if(a >= k) gold_cnt += a;
            if(!a && gold_cnt) {
                ans++;
                gold_cnt--;
            }
        }

        cout << ans << "\n";
    }
}







