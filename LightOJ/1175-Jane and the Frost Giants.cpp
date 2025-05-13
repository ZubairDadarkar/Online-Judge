#include <bits/stdc++.h>
#define ll long long
#define MAX 202

using namespace std;

int r, c;
char grid[MAX][MAX];
vector<vector<int>> disF, dis;

int dr[] = {-1, +1, 0, 0};
int dc[] = {0, 0, -1, +1};

void inputsGrid();
pair<int, int> findsJane();
void fireBFS();
int solveBFS(int x, int y);
bool isValidCell(int x, int y);
void printsDis(vector<vector<int>> dis);

int main() {
    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; i++) {
        inputsGrid();

        pair<int, int> u = findsJane();
        int ur = u.first;
        int uc = u.second;

        fireBFS();
        int ans = solveBFS(ur, uc);

        cout << "Case " << i << ": ";
        if(ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }
}

int solveBFS(int x, int y) {
    dis.clear();
    dis.resize(r, vector<int> (c, -1));
    queue<pair<int, int>> Q;

    dis[x][y] = 0;
    Q.push({x, y});

    while(!Q.empty()) {
        pair<int, int> u = Q.front();
        Q.pop();
        int ur = u.first;
        int uc = u.second;
        for(int i = 0; i < 4; i++) {
            int vr = ur + dr[i];
            int vc = uc + dc[i];
            if(!isValidCell(vr, vc)) return (dis[ur][uc] + 1);
            if(grid[vr][vc] == '#' ||
               dis[vr][vc] != -1 ||
               disF[vr][vc] <= dis[ur][uc]+1) continue;
            dis[vr][vc] = dis[ur][uc] + 1;
            Q.push({vr, vc});
        }
    }

    return -1;
}

void fireBFS() {
    disF.clear();
    disF.resize(r, vector<int> (c, -1));
    queue<pair<int, int>> fireQ;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(grid[i][j] == 'F') {
                fireQ.push({i, j});
                disF[i][j] = 0;
            }
        }
    }

    while(!fireQ.empty()) {
        pair<int, int> u = fireQ.front();
        fireQ.pop();
        int ur = u.first;
        int uc = u.second;
        for(int i = 0; i < 4; i++) {
            int vr = ur + dr[i];
            int vc = uc + dc[i];
            if(!isValidCell(vr, vc) ||
               grid[vr][vc] == '#' ||
               disF[vr][vc] != -1) continue;
            disF[vr][vc] = disF[ur][uc] + 1;
            fireQ.push({vr, vc});
        }
    }
}

bool isValidCell(int x, int y) {
    return (0 <= x && x < r && 0 <= y && y < c);
}

void inputsGrid() {
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        cin >> grid[i];
    }
}

pair<int, int> findsJane() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(grid[i][j] == 'J')
                return {i, j};
        }
    }
    return {-1, -1};
}

void printsDis(vector<vector<int>> dis) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << dis[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
