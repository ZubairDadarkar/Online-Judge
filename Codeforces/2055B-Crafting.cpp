#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
vector<int> A;

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
    cin >> n;
    A.clear(); A.resize(n);
    for(int i = 0; i < n; i++) cin >> A[i];
}

void SolveCase() {
    int min_neg = 0, min_pos = INT_MAX;
    int neg_cnt = 0;
    for(int i = 0; i < n; i++) {
        int b; cin >> b;
        int diff = A[i] - b;

        if(diff < 0) {
            neg_cnt++;
            if(min_neg > diff) min_neg = diff;
        }
        else {
            if(min_pos > diff) min_pos = diff;
        }
    }

    if(neg_cnt > 1 || abs(min_neg) > min_pos) cout << "NO\n";
    else cout << "YES\n";
}
