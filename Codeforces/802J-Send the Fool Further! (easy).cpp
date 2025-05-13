#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
vector<vector<pair<int, int>>> tree;
vector<int> cost;

void InputTree();
int BFS(int);

int main() {
    cin >> n;

    InputTree();
    int ans = BFS(0);

    cout << ans << "\n";

    return 0;
}

int BFS(int root) {
    cost.clear(); cost.resize(n, -1);
    queue<pair<int, int>> q;

    int res = 0;
    cost[root] = 0;
    q.push({root, cost[root]});

    while(!q.empty()) {
        int u, uc;
        tie(u, uc) = q.front();
        if(res < uc) res = uc;
        q.pop();

        for(int i = 0; i < tree[u].size(); i++) {
            int v, vc;
            tie(v, vc) = tree[u][i];
            if(cost[v] != -1) continue;
            cost[v] = uc + vc;
            q.push({v, cost[v]});
        }
    }

    return res;
}

void InputTree() {
    tree.clear(); tree.resize(n);

    for(int i = 0; i < n-1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        tree[u].push_back({v, c});
        tree[v].push_back({u, c});
    }
}

