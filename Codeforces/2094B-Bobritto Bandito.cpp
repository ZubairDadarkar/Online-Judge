#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n, m, l, r;

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
    cin >> n >> m >> l >> r;
}

void SolveCase() {
    if(m <= r) {
        r = m;
        l = 0;
    }
    else {
        m -= r;
        l = 0 - m;
    }

    cout << l << " " << r << "\n";
}
