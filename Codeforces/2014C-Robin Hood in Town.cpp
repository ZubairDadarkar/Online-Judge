#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

vector<int> wealth;
int n;
ll total_wealth;

ll BinarySearch();
bool IsPossibleX(ll);

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        total_wealth = 0L;
        wealth.clear(); wealth.resize(n, 0);

        for(int i = 0; i < n; i++)
            cin >> wealth[i], total_wealth += wealth[i];

        ll ans;

        if(n <= 2) ans = -1;
        else {
            sort(wealth.begin(), wealth.end());
            ans = BinarySearch();
        }

        cout << ans << "\n";
    }
}

ll BinarySearch() {
    ll left = 0, right = 1e15;

    while(left < right) {
        ll mid = left + (right - left) / 2;
        if( IsPossibleX(mid) ) right = mid;
        else left = mid+1;
    }

    return left;
}

bool IsPossibleX(ll x) {
    ll avg_wealth = ( total_wealth+x + n - 1 ) / n; // ceil value
    ll half_avg_wealth = ( avg_wealth + 2 -1 ) / 2; // ceil value
    return ( wealth[n/2] < half_avg_wealth );
}

