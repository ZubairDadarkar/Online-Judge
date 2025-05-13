#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

string s;

void ReadCase() {
    cin >> s;
}

int SolveCase() {
    int n = s.size();

    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) return 1;
    }

    return n;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        ReadCase();
        cout << SolveCase() << "\n";

    }

    return 0;
}

