#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n, m;
string s;
vector<vector<ll>> A;

void ReadCase();
void SolveCase();
void PrintAns();

int main() {
    int t;
    cin >> t;

    while(t--) {
        ReadCase();
        SolveCase();
        PrintAns();
    }

    return 0;
}

void ReadCase() {
    cin >> n >> m >> s;

    A.clear();
    A.resize(n, vector<ll> (m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> A[i][j];
}

void SolveCase() {
    int row = 0, col = 0;
    ll sum;

    for(char ch : s) {
        sum = 0;
        if(ch == 'D') {
            for(int i = 0; i < m; i++)
                sum += A[row][i];
            A[row][col] = -sum;
            row++;
        }
        else {
            for(int i = 0; i < n; i++)
                sum += A[i][col];
            A[row][col] = -sum;
            col++;
        }
    }

    sum = 0;
    for(int i = 0; i < m; i++)
        sum += A[row][i];

    A[row][col] = -sum;
}

void PrintAns() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}
