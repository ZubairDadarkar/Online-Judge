#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n, m;
vector<int> A, B;

void ReadCase() {
    cin >> n >> m;

    A.clear(); A.resize(n);
    B.clear(); B.resize(m);

    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < m; i++) cin >> B[i];
}

bool SolveCase() {
    int x = B[0];

    A[0] = min(A[0], x-A[0]);
    for(int i = 1; i < n; i++) {
        if(A[i-1] <= A[i]) {
            int temp = x-A[i];
            if(temp >= A[i]) continue;
            if(A[i-1] <= temp) A[i] = temp;
        }
        else {
            int temp = x-A[i];
            if(A[i-1] > temp) return false;
            else A[i] = temp;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        ReadCase();

        if(SolveCase()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

