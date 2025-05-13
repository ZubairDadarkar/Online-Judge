#include <bits/stdc++.h>
#define ll long long
#define MAX 1003

using namespace std;

int n, m;
int grid[MAX][MAX];
int vis[MAX][MAX];

int dr[] = {-1, +1, 0, 0};
int dc[] = {0, 0, -1, +1};

void gridInput();
int DFS(int ur, int uc);
bool isValidCell(int r, int c);

int main() {
    int t;
    cin >> t;
    while(t--) {
        gridInput();
        memset(vis, 0, sizeof vis);
        int maxVol = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j] || vis[i][j]) continue;
                maxVol = max(maxVol, DFS(i, j));
            }
        }
        cout << maxVol << "\n";
    }
}

int DFS(int ur, int uc) {
    vis[ur][uc] = 1;
    int totalVol = grid[ur][uc];
    for(int i = 0; i < 4; i++) {
        int vr = ur + dr[i];
        int vc = uc + dc[i];
        if(!isValidCell(vr, vc) || !grid[vr][vc] || vis[vr][vc]) continue;
        totalVol += DFS(vr, vc);
    }
    return totalVol;
}

bool isValidCell(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < m);
}

void gridInput() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
}
