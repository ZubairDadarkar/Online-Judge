#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
vector<int> arr;

void ReadCase();
void SolveCase();

int main() {
    ReadCase();
    SolveCase();

    return 0;
}

void ReadCase() {
    cin >> n;
    arr.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
}

void SolveCase() {
    int ans = 0;
    for(int i = 1; i < n; i++) {
        int t = log2(n-i);
        int d = pow(2, t);
        arr[i + d] += arr[i];
        ans += arr[i];
        cout << ans << "\n";
    }
}
