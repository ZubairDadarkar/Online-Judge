#include <bits/stdc++.h>
#define ll long long
#define MAX 1003

using namespace std;

int dr[] = {-1, +1, 0, 0};
int dc[] = {0, 0, -1, +1};

int n, m;
char grid[MAX][MAX];
int vis[MAX][MAX];

bool isValidCell(int r, int c);
int DFS(int ur, int uc);

int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> m >> n;
        for(int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        int ur, uc;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '@') ur = i, uc = j;
            }
        }

//        cout << ur << " " << uc << "\n";
        memset(vis, 0, sizeof vis);
        cout << "Case " << i << ": " << DFS(ur, uc) << "\n";
    }
}

bool isValidCell(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < m);
}

int DFS(int ur, int uc) {
    vis[ur][uc] = 1;
    int cnt = 1;
    for(int i = 0; i < 4; i++) {
        int vr = ur + dr[i];
        int vc = uc + dc[i];
        if(isValidCell(vr, vc) && grid[vr][vc] != '#' && !vis[vr][vc])
            cnt += DFS(vr, vc);
    }
    return cnt;
}

