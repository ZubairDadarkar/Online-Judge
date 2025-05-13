#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
vector<ll> arr;
vector<ll> prefix, suffix;

void ReadCase();
void SolveCase();
void CalcPrefix();
void CalcSuffix();

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
    cin >> n;
    arr.clear(); arr.resize(n);

    for(int i = 0; i < n; i++) cin >> arr[i];
}

void CalcPrefix() {
    prefix.clear(); prefix.resize(n, 0);

    if(arr[0] > 0)
        prefix[0] = arr[0];

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1];

        if(arr[i] > 0)
            prefix[i] += arr[i];
    }
}

void CalcSuffix() {
    suffix.clear(); suffix.resize(n, 0);

    if(arr[n-1] < 0)
        suffix[n-1] = -arr[n-1];

    for(int i = n-2; i >= 0; i--) {
        suffix[i] = suffix[i+1];

        if(arr[i] < 0)
            suffix[i] -= arr[i];
    }
}

void SolveCase() {
    CalcPrefix();
    CalcSuffix();

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, prefix[i] + suffix[i]);
    }

    cout << ans << "\n";
}
