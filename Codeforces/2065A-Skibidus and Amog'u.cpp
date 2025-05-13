#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string w;
        cin >> w;
        w = w.substr(0, w.size()-2);
        w += 'i';
        cout << w << "\n";
    }

    return 0;
}

