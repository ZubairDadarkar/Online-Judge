#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int a, b, c;

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
    cin >> a >> b >> c;
}

void SolveCase() {
    int sum = a + b + c;
    int mod = sum % 3;

    if(mod) {
        cout << "NO\n";
        return;
    }

    int avg = sum / 3;

    if(a > avg || b > avg || c < avg) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}
