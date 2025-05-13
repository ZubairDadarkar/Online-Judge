#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
vector<ll> arr;

void ReadCase();
void SolveCase();

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
    arr.clear();
    arr.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void SolveCase() {
    for(int i = 1; i < n; i++) {
        ll x = arr[i-1] + arr[i] - 1;
        arr[i] = x;
    }

    cout << arr[n-1] << "\n";
}
