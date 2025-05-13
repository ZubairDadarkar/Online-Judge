#include <bits/stdc++.h>
#define ll long long
#define MAX 203

using namespace std;

int n, l;
vector<vector<int>> graph;
vector<int> col;

bool DFS(int u, int c);

bool DFS(int u, int c) {
    col[u] = c;
    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(col[v] == col[u]) return false;
        if(col[v]) continue;
        if(!DFS(v, 3-c)) return false;
    }
    return true;
}

int main() {
    while(1) {
        cin >> n;
        if(!n) break;
        cin >> l;

        graph.clear(); graph.resize(n+1);
        col.clear(); col.resize(n+1, 0);

        for(int i = 0; i < l; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if(DFS(0, 1)) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";


    }
}

/**
3
3
0 1
1 2
2 0
3
2
0 1
1 2
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0
*/
