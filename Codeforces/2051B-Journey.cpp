#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

ll n;
vector<ll> day;
ll sum;

void ReadCase() {
    cin >> n;
    day.clear(); day.resize(3);
    sum = 0;
    for(int i = 0; i < 3; i++) {
        cin >> day[i];
        sum += day[i];
    }
}

ll SolveCase() {
    ll div = n/sum;
    ll ans = 3*div;
//    cout << ans << "\n";
    ll cur_km = sum*div;

    int i = 0;
    while(cur_km < n) {
        ans++;
        cur_km += day[i++];
    }

    return ans;
}

int main() {
    int t; cin >> t;
    while(t--) {
        ReadCase();
//        for(int i = 0; i < 3; i++) cout << day[i] << " ";
//        cout << "\n";
//        cout << sum << "\n";
        cout << SolveCase() << "\n";
    }

    return 0;
}

