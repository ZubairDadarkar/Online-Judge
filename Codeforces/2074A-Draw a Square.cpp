#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int l, r, d, u;

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
    cin >> l >> r >> d >> u;
}

void SolveCase() {
    int lu = sqrt(l*l + u*u);
    int ur = sqrt(u*u + r*r);
    int rd = sqrt(r*r + d*d);
    int dl = sqrt(d*d + l*l);

    if(lu == ur && ur == rd && rd == dl && l+r == d+u) cout << "YES\n";
    else cout << "NO\n";
}
