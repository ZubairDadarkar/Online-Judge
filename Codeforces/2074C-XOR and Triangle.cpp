#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
int x;

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
    cin >> x;
}

bool IsValidTriangle(int a, int b, int c) {
    return (a+b > c && b+c > a && c+a > b);
}

void SolveCase() {
    for(int i = 0; i < 32; i++) {
        int y = pow(2, i) - 1;

        if(y >= x) {
            cout << "-1\n";
            return;
        }

        int z = x ^ y;

        if(IsValidTriangle(x, y, z) == true) {
            cout << y << "\n";
            return;
        }
    }
}
