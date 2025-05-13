#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n, k;
vector<int> A;

void ReadCase() {
    cin >> n >> k;
    A.clear(); A.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        if(i) A[i] += A[i-1];
    }
}

int SolveCase() {
    int min_sum = INT_MAX;
    int ans = -1;
    for(int i = 0, j = k-1; j < n; i++, j++) {
        int sum = A[j];
        if(i) sum -= A[i-1];
        if(min_sum > sum) {
            min_sum = sum;
            ans = i;
        }
    }

    return ans+1;
}

int main() {
    ReadCase();
//    for(int i = 0; i < n; i++) cout << A[i] << " ";
//    cout << "\n";
    cout << SolveCase() << "\n";
    return 0;
}

