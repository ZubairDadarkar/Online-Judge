#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
ll col_a = 0L, col_b = 0L;
vector<vector<int>> tree;
vector<int> col;

void InputTree();
void BFS(int);

int main() {
    cin >> n;

    InputTree();
    BFS(1);
    ll ans = (col_a * col_b) - (n - 1);
    cout << ans << "\n";

    return 0;
}

void BFS(int root) {
    col.clear(); col.resize(n+1, 0);
    queue<int> q;

    q.push(root);
    col[root] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(col[u] == 1) col_a++;
        else col_b++;

        for(int i = 0; i < tree[u].size(); i++) {
            int v = tree[u][i];
            if(col[v]) continue;
            col[v] = 3 - col[u];
            q.push(v);
        }
    }
}

void InputTree() {
    tree.clear(); tree.resize(n+1);

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}












