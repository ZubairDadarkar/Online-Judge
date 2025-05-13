#include <bits/stdc++.h>
#define ll long long
#define MAX 100005

using namespace std;

int cnt1, cnt2;
vector<vector<int>> graph;
vector<int> col;
set<int> nodes;

void DFS(int u, int c);

void DFS(int u, int c) {
    if(c == 1) cnt1++;
    else cnt2++;
    col[u] = c;
    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(col[v]) continue;
        DFS(v, 3-c);
    }
}

int main() {
    int t;
    cin >> t;
    for(int c = 1; c <= t; c++) {
        int n;
        cin >> n;

        graph.clear(); graph.resize(MAX);
        col.clear(); col.resize(MAX, 0);
        nodes.clear();

        for(int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            nodes.insert(u);
        }

        int ans = 0;
        for(int u : nodes) {
            if(!col[u]) {
                cnt1 = 0, cnt2 = 0;
                DFS(u, 1);
                ans += max(cnt1, cnt2);
            }
        }
        cout << "Case " << c << ": " << ans << "\n";
    }
}
