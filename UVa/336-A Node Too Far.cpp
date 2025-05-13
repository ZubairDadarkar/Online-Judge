#include <bits/stdc++.h>

using namespace std;

int nc, caseCnt = 1;
map<int, vector<int>> M;
map<int, int> level;

void inputsGraph();
void printsGraph();
void BFS(int root);

int main() {
//    freopen("336-A Node Too Far_Input.txt", "r", stdin);
//    freopen("336-A Node Too Far_Output.txt", "w", stdout);

    while(1) {
        cin >> nc;
        if(!nc) break;

        M.clear();
        inputsGraph();

        while(1) {
            int u, ttl;
            cin >> u >> ttl;
            if(!u && !ttl) break;

            if(M.find(u) == M.end()) {
                cout << "Case " << caseCnt++ << ": " << M.size()
                << " nodes not reachable from node " << u
                << " with TTL = " << ttl << ".\n";

                continue;
            }

            level.clear();

            for(auto node : M) {
                level[node.first] = -1;
            }

            BFS(u);

            int unvisCnt = 0;
            for(auto i : level) {
                if(i.second > ttl || i.second == -1) {
                    unvisCnt++;
//                    cout << i.first << " ";
                }
            }
//            cout << "\n";

            cout << "Case " << caseCnt++ << ": " << unvisCnt
                << " nodes not reachable from node " << u
                << " with TTL = " << ttl << ".\n";
        }
    }

    return 0;
}

void BFS(int root) {
    queue<int> Q;
    Q.push(root);
    level[root] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < M[u].size(); i++) {
            int v = M[u][i];
            if(level[v] >= 0) continue;
            level[v] = level[u]+1;
            Q.push(v);
        }
    }
}

void inputsGraph() {
    for(int i = 0; i < nc; i++) {
        int u, v;
        cin >> u >> v;
        M[u].push_back(v);
        M[v].push_back(u);
    }
//    printsGraph();
}

void printsGraph() {
    for(auto x : M) {
        cout << x.first << " -> ";
        for(int i = 0; i < x.second.size(); i++)
            cout << x.second[i] << " ";
        cout << "\n";
    }
    cout << "\n";
}

/**
16
10 15 15 20 20 25 10 30 30 47 47 50 25 45 45 65
15 35 35 55 20 40 50 55 35 40 55 60 40 60 60 65
35 2 35 3 0 0
14
1 2 2 7 1 3 3 4 3 5 5 10 5 11
4 6 7 6 7 8 7 9 8 9 8 6 6 11
1 1 1 2 3 2 3 3 0 0
0
*/

/**
12
62 99  11 54  9 21  15 54  36 39  75 11
39 9  9 24  62 92  21 75  25 92  92 14
75 5  9 7  96 7  15 5   15 0  0 0
0
*/
