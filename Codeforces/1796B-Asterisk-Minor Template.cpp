#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

string A, B;

void ReadCase() {
    cin >> A >> B;
}

void SolveCase() {
    int m = A.size(), n = B.size();
    if(A[0] == B[0]) {
        cout << "YES\n";
        cout << A[0] << "*" << "\n";
        return;
    }
    if(A[m-1] == B[n-1]) {
        cout << "YES\n";
        cout << "*" << A[m-1] << "\n";
        return;
    }

    for(int i = 0; i < m-1; i++) {
        for(int j = 0; j < n-1; j++) {
            if(A[i] == B[j] && A[i+1] == B[j+1]) {
                cout << "YES\n";
                cout << "*" << A[i] << A[i+1] << "*" << "\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        ReadCase();
        SolveCase();
    }

    return 0;
}

