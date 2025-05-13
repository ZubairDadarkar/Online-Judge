#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<char>> grid(n, vector<char> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j] ;

        int s = n/k;
        for(int i = 0; i < s; i++) {
            for(int j = 0; j < s; j++)
                cout << grid[i*k][j*k];
            cout << "\n";
        }
    }
}
