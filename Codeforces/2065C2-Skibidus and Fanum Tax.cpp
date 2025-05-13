#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n, m;
vector<int> A, B;

int LowerBound(int target) {
    int left = 0;
    int right = B.size();

    while(left < right) {
        int mid = left + (right - left) / 2;
        if(B[mid] < target) left = mid + 1;
        else right = mid;
    }

    return left;
}

void ReadCase() {
    cin >> n >> m;

    A.clear(); A.resize(n);
    B.clear(); B.resize(m);

    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < m; i++) cin >> B[i];
}

bool SolveCase() {
    sort(B.begin(), B.end());
    A[0] = min(A[0], min(B[0]-A[0], B[m-1]-A[0]));

    for(int i = 1; i < n; i++) {
        if(A[i-1] <= A[i]) {
            int target = A[i-1] + A[i];

            int b_idx = LowerBound(target);
            if(b_idx == m) continue;

            A[i] = B[b_idx] - A[i];
        }
        else {
            int target = A[i-1] + A[i];

            int b_idx = LowerBound(target);
            if(b_idx == m) return false;

            A[i] = B[b_idx] - A[i];
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


