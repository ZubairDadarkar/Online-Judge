#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
vector<vector<int>> tree;
vector<bool> vis;
vector<int> roots, lev;

void InputTree();
int BFS(int);

int main() {
    cin >> n;
    InputTree();

    vis.clear(); vis.resize(n+1, false);
    lev.clear(); lev.resize(n+1, 0);

    int ans = 0;
    for(int i = 0; i < roots.size(); i++) {
        ans = max(ans, BFS(roots[i]));
    }

    cout << ans+1 << "\n";

    return 0;
}

int BFS(int root) {
    queue<int> q;
    q.push(root);

    int u;
    while(!q.empty()) {
        u = q.front();
        vis[u] = true;
        q.pop();

        for(int i = 0; i < tree[u].size(); i++) {
            int v = tree[u][i];
            if(vis[v]) continue;
            lev[v] = lev[u] + 1;
            q.push(v);
        }
    }

    return lev[u];
}

void InputTree() {
    tree.clear(); tree.resize(n+1);
    for(int i = 1; i <= n; i++) {
        int v; cin >> v;
        if(v == -1) {
            roots.push_back(i);
            continue;
        }
        tree[i].push_back(v);
        tree[v].push_back(i);
    }
}

