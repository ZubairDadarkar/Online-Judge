#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
vector<vector<int>> grid;

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
    grid.clear();
    grid.resize(n+1, vector<int> (n+1));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
}

void SolveCase() {
    int m = 2*n;
    vector<int> ans(m+1, 0);

    int total_sum = (m * (m + 1)) / 2;
    int curr_sum = 0;

    for(int i = 2; i <= m; i++) {
        int x = i/2;
        int y = i-x;

        int val = grid[x][y];

        ans[i] = val;
        curr_sum += val;
    }

    ans[1] = total_sum-curr_sum;

    for(int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
