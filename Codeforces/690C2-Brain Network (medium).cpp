#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> lev;

void InputGraph();
int BFS(int);

int main() {
    cin >> n >> m;

    InputGraph();

    int farthest_node = BFS(1);
    farthest_node = BFS(farthest_node);

    cout << lev[farthest_node] << "\n";

    return 0;
}

int BFS(int root) {
    lev.clear(); lev.resize(n+1, -1);
    queue<int> q;

    lev[root] = 0;
    q.push(root);

    int u;
    while(!q.empty()) {
        u = q.front();
        q.pop();

        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if(lev[v] != -1) continue;
            lev[v] = lev[u] + 1;
            q.push(v);
        }
    }

    return u;
}

void InputGraph() {
    graph.clear(); graph.resize(n+1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

