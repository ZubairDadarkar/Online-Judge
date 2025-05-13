#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0, num;
        for(int i = 1; i <= n; i++) {
            cin >> num;
            ans = __gcd(ans, abs(num-i));
        }
        cout << ans << "\n";
    }
}
