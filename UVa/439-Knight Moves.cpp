#include <bits/stdc++.h>
#define ll long long
#define MAX 10

using namespace std;

vector<vector<int>> dis;

int dr[] = {-1, -2, -2, -1, +1, +2, +2, +1};
int dc[] = {-2, -1, +1, +2, +2, +1, -1, -2};

void solveBFS(int, int);
bool isValidCell(int, int);

int main() {
    string str;
    while( getline(cin, str) && str.compare("") ) {
        string start = "", dest = "";

        int s;
        for(s = 0; str[s] != ' '; s++) start += str[s];
        for(s = s+1; str[s] != '\0'; s++) dest += str[s];

        int ur = (start[0] - 'a');
        int uc = (start[1] - '1');
        int vr = (dest[0] - 'a');
        int vc = (dest[1] - '1');

//        cout << ur << " " << uc << "\n" << vr << " " << vc << "\n";

        solveBFS(ur, uc);

        int ans = dis[vr][vc];
        cout << "To get from " << start << " to " << dest << " takes " << ans << " knight moves.\n";
    }
}

void solveBFS(int x, int y) {
    dis.clear();
    dis.resize(8, vector<int> (8, -1));
    queue<pair<int, int>> Q;

    dis[x][y] = 0;
    Q.push({x, y});

    while(!Q.empty()) {
        pair<int, int> u = Q.front();
        int ur = u.first;
        int uc = u.second;
        Q.pop();

        for(int i = 0; i < 8; i++) {
            int vr = ur + dr[i];
            int vc = uc + dc[i];

            if(!isValidCell(vr, vc) ||  dis[vr][vc] != -1) continue;

            dis[vr][vc] = dis[ur][uc]+1;
            Q.push({vr, vc});
        }
    }
}

bool isValidCell(int r, int c) {
    return (0 <= r && r < 8 && 0 <= c && c < 8);
}

/**
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6
*/
