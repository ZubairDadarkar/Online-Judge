#include <bits/stdc++.h>
#define ll long long
#define MAX 100005

using namespace std;

vector<ll> arr;
int n, c;

bool IsPossible(ll min_allowed) {
    ll cow_cnt = 1, last_pos = arr[0];

    for(int i = 0; i < n; i++) {
        if(arr[i]-last_pos >= min_allowed) {
            cow_cnt++;
            last_pos = arr[i];
        }

        if(cow_cnt == c) return true;
    }

    return false;
}

int solve(ll small_val, ll lerge_val) {
    ll l = small_val+1, r = lerge_val-1, ans = -1;

    while(l <= r) {
        ll mid = l + (r - l)/2;
        if(IsPossible(mid)) {
            ans = mid;
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }

    return ans;
}

int main() {
    int t; cin >> t;

    while(t--) {
        cin >> n >> c;
        arr.clear(); arr.resize(n);

        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());

        cout << solve(arr[0], arr[n-1]) << "\n";
    }

    return 0;
}


