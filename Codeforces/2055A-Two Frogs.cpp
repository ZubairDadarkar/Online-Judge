#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n, a, b;

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
    cin >> n >> a >> b;
}

void SolveCase() {
    int diff = abs(a - b);
    if(diff % 2) cout << "NO\n";
    else cout << "YES\n";
}

