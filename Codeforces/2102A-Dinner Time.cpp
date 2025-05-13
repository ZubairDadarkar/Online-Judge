#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n, m, p, q;

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

}

void ReadCase() {
    cin >> n >> m >> p >> q;
}

void SolveCase() {
    int mod = n % p;
    int div = n / p;

    if(mod == 0) {
        if(div * q == m) cout << "YES\n";
        else cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

void PrintCase() {

}

