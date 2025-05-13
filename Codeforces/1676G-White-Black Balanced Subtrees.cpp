#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n, ans;
string color;
vector<vector<int>> tree;
vector<bool> vis;

void InputTree();
pair<int, int> DFS(int, int, int);

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        InputTree();
        string str; cin >> str;
        color = "#" + str;
        ans = 0;

        vis.clear(); vis.resize(n+1, false);
        DFS(1, 0, 0);

        cout << ans << "\n";
    }

    return 0;
}

pair<int, int> DFS(int u, int w, int b) {
    if(color[u] == 'W') w++;
    else b++;

    for(int i = 0; i < tree[u].size(); i++) {
        int v = tree[u][i];
        int cnt_w, cnt_b;
        tie(cnt_w, cnt_b) = DFS(v, 0, 0);
        w += cnt_w;
        b += cnt_b;
    }
    if(w == b) ans++;

    return {w, b};
}

void InputTree() {
    tree.clear(); tree.resize(n+1);

    for(int i = 2; i <= n; i++) {
        int u; cin >> u;
        tree[u].push_back(i);
    }
}











