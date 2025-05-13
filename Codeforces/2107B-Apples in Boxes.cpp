#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

ll n, k;
ll max_val, min_val;
ll sum;
vector<ll> arr;

void InitCase();
void ReadCase();
void SolveCase();
void PrintCase();

int main() {
    int t;
    cin >> t;

    while(t--) {
        InitCase();
        ReadCase();
        SolveCase();
        PrintCase();
    }

    return 0;
}

void InitCase() {
    arr.clear();
    min_val = LLONG_MAX;
    max_val = LLONG_MIN;
    sum = 0LL;
}

void ReadCase() {
    cin >> n >> k;

    arr.resize(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
}

void SolveCase() {
    sort(arr.begin(), arr.end());
    min_val = arr[0];
    max_val = arr[n-1];

    if(max(max_val-1, arr[n-2]) - min_val > k) {
        cout << "Jerry\n";
        return;
    }

    if(sum % 2LL) {
        cout << "Tom\n";
    }
    else {
        cout << "Jerry\n";
    }
}

void PrintCase() {

}

