#include <bits/stdc++.h>
#define ll long long
#define MAX 202

using namespace std;

int n, m;
char grid[MAX][MAX];
pair<int, int> startPosi, destination;
vector<pair<int, int>> teleportCells;
vector<vector<int>> dis;
queue<pair<int, int>> Q;

int dr[] = {-1, +1, 0, 0};
int dc[] = {0, 0, -1, +1};

void traversGrid();

tuple<int, int, int> findsNearestTele(int x, int y);
tuple<int, int, int> findsStartNearestTele(int x, int y, int dx, int dy);
int findsDisWithoutTele(int x, int y);
bool isValidCell(int x, int y);

void enqueueTeleports(int r, int c, int d);
void printsDis(vector<vector<int>> dis);
void printsGrid();

int main() {
//    freopen("1377-Blade and Sword_Input.txt", "r", stdin);
//    freopen("1377-Blade and Sword_Output.txt", "w", stdout);

    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> grid[i];

        traversGrid();

        int sr = startPosi.first; // Start position row
        int sc = startPosi.second; // Start position column

        int dr = destination.first; // Destination position row
        int dc = destination.second; // Destination position column

//        cout << sr << " " << sc << "\n";
//        cout << dr << " " << dc << "\n";

        int destTeleR = -1, destTelC = -1, destTeleDis = -1; // destTeleR = Nearest teleport row, destTelC = Nearest teleport column, destTeleDis = Nearest teleport distance
        tuple<int, int, int> nearestTele = findsNearestTele(dr, dc); // Finds the nearest teleports cell of destination
        tie(destTeleR, destTelC, destTeleDis) = nearestTele;

//        cout <<destTeleR << " " << destTelC << " " << destTeleDis << "\n";

        int startTeleR = -1, startTelC = -1, startTeleDis = -1; // startTeleR = Nearest teleport row, startTelC = Nearest teleport column, startTeleDis = Nearest teleport distance
        if(destTeleDis != -1) {
            nearestTele = findsStartNearestTele(sr, sc, destTeleR, destTelC); // Finds the nearest teleports cell of start position
            tie(startTeleR, startTelC, startTeleDis) = nearestTele;
        }

//        cout <<startTeleR << " " << startTelC << " " << startTeleDis << "\n";

//        printsDis(dis);

        int disUsingTele; // Distance using teleport

        if(destTeleDis == -1 || startTeleDis == -1) {
            disUsingTele = -1;
            if(teleportCells.size()) {
                int x = teleportCells[0].first;
                int y = teleportCells[0].second;
                grid[x][y] = '#';
            }
        }
        else disUsingTele = destTeleDis + startTeleDis + 1;

//        cout << "disUsingTele = " << disUsingTele << "\n";

        int disWithoutTele = findsDisWithoutTele(sr, sc);

//        cout << "disWithoutTele = " << disWithoutTele << "\n";

        int ans = -1;
        if(disUsingTele == -1) ans = disWithoutTele;
        else if(disWithoutTele == -1) ans = disUsingTele;
        else ans = min(disUsingTele, disWithoutTele);

        cout << "Case " << i << ": ";
        if(ans == -1) cout << "impossible\n";
        else cout << ans << "\n";
    }

    return 0;
}

tuple<int, int, int> findsNearestTele(int x, int y) {
    dis.clear(); dis.resize(n, vector<int> (m, -1));
    Q = queue<pair<int, int>> ();

    dis[x][y] = 0;
    Q.push({x, y});

    while(!Q.empty()) {
        pair<int, int> u = Q.front();
        int ur = u.first;
        int uc = u.second;
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int vr = ur + dr[i];
            int vc = uc + dc[i];

            if(grid[vr][vc] == '*') return {vr, vc, dis[ur][uc]+1};

            if(!isValidCell(vr, vc) || grid[vr][vc] == '#' || dis[vr][vc] != -1)
                continue;

            dis[vr][vc] = dis[ur][uc]+1;
            Q.push({vr, vc});
        }
    }

    return {-1, -1, -1};
}

tuple<int, int, int> findsStartNearestTele(int x, int y, int dx, int dy) {
    dis.clear(); dis.resize(n, vector<int> (m, -1));
    Q = queue<pair<int, int>> ();
//    cout << x << " " << y << "\n";
    dis[x][y] = 0;
    Q.push({x, y});

    while(!Q.empty()) {
        pair<int, int> u = Q.front();
        int ur = u.first;
        int uc = u.second;
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int vr = ur + dr[i];
            int vc = uc + dc[i];

            if(grid[vr][vc] == '*') {
                if(vr == dx && vc == dy) continue;
                return {vr, vc, dis[ur][uc]+1};
            }

            if(!isValidCell(vr, vc) || grid[vr][vc] == '#' || dis[vr][vc] != -1)
                continue;

            dis[vr][vc] = dis[ur][uc]+1;
            Q.push({vr, vc});
        }
    }

    return {-1, -1, -1};
}

int findsDisWithoutTele(int x, int y) {
    dis.clear();
    dis.resize(n, vector<int> (m, -1));
    Q = queue<pair<int, int>> ();

    dis[x][y] = 0;
    Q.push({x, y});

    while(!Q.empty()) {
        pair<int, int> u = Q.front();
        int ur = u.first;
        int uc = u.second;
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int vr = ur + dr[i];
            int vc = uc + dc[i];

            if(grid[vr][vc] == 'D') return (dis[ur][uc] + 1);
            if(!isValidCell(vr, vc) || grid[vr][vc] != '.' || dis[vr][vc] != -1) continue;

            dis[vr][vc] = dis[ur][uc]+1;
            Q.push({vr, vc});
        }
    }
    return -1;
}

void traversGrid() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '*') teleportCells.push_back({i, j});
            else if(grid[i][j] == 'P') startPosi = {i, j};
            else if(grid[i][j] == 'D') destination = {i, j};
        }
    }
}

bool isValidCell(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

///* For test purpose ---------------------------------------------------------------------------------
//void findsTeleportCells() {
//    teleportCells.clear();
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            if(grid[i][j] == '*')
//                teleportCells.push_back({i, j});
//        }
//    }
//}

//void enqueueTeleports(int r, int c, int d) {
//    cout << d << "\n";
//    grid[r][c] = '#';
//    for(int i = 0; i < teleportCells.size(); i++) {
//        int tr = teleportCells[i].first;
//        int tc = teleportCells[i].second;
//        if(tr == r && tc == c) continue;
//        dis[tr][tc] = d+1;
//        Q.push({tr, tc});
//    }
//}


//pair<int, int> findsP() {
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            if(grid[i][j] == 'P')
//                return {i, j};
//        }
//    }
//
//    return {-1, -1};
//}

void printsDis(vector<vector<int>> dis) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%4d", dis[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";
}

void printsGrid() {
    for(int i = 0; i < n; i++)
        cout << grid[i] << "\n";
    cout << "\n";
}

//*/

/**
10
11 10
##########
#*#.....D#
###.###.##
#...#.#..#
#.....##.#
#####*####
#........#
#........#
#........#
#P.......#
##########
4 6
######
#.*D.#
#.P*.#
######
5 5
#####
#D..#
#...#
#..P#
#####
6 3
###
#.#
#P#
#D#
###
###
*/
