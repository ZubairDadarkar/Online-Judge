#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int m, total, ans;

vector<int> arr;
vector<vector<int>> dp;

void ReadCase() {
    cin >> m;

    arr.clear();
    arr.resize(m);

    total = 0;
    for(int i = 0; i < m; i++) {
        cin >> arr[i];
        total += arr[i];
    }
}

int solve(int i, int sum1) {
    if(dp[i][sum1] != -1) return dp[i][sum1];

    if(i == m) {
        int sum2 = total - sum1;
        return dp[i][sum1] = abs(sum1 - sum2);
    }

    int left = solve(i+1, sum1);
    if(!left)
        return 0;

    int right;
    if(sum1+arr[i] <= total/2) {
        right = solve(i+1, sum1+arr[i]);
    }
    else
        return left;

    if(left < right)
        return dp[i][sum1] = left;

    return dp[i][sum1] = right;
}

void SolveCase() {
    dp.clear();
    dp.resize(m+1, vector<int>(total+1, -1));

    ans = solve(0, 0);
}

void PrintCase() {
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        ReadCase();
        SolveCase();
        PrintCase();
    }

    return 0;
}

/**
2
3
2 3 5
4
1 2 4 6
*/

