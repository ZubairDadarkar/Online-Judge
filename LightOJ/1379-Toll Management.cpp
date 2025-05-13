#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n, m, s, d, p;
vector<vector<pair<int, int> > > graph;
vector<vector<int>> dis;

void graphInput();
int dijkstraAlgo(int);

int main() {
    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n >> m >> s >> d >> p;
        graphInput();
        int ans = dijkstraAlgo(s);

        cout << "Case " << i << ": " << ans << "\n";
    }
}

int dijkstraAlgo(int s) {
    dis.clear(); dis.resize(p+1, vector<int> (n+1, INT_MIN));
    priority_queue<tuple<int, int, int>> pq;
    int ans = -1;

    dis[0][s] = 0;
    pq.push({0, s, p});

    while(!pq.empty()) {
        int c, u, p_;
        tie(c, u, p_) = pq.top();
        c = -c;
        pq.pop();

        if(u == d) ans = max(ans, c);

        for(int i = 0; i < graph[u].size(); i++) {
            int v, w;
            tie(v, w) = graph[u][i];

            if(p_ < w) continue;

            p_ -= w;
            if(max(w, c) > dis[p_][v]) {
                dis[p_][v] = max(w, c);
                pq.push({-dis[p_][v], v, p_});
            }
        }
    }

    return ans;
}

void graphInput() {
    graph.clear(); graph.resize(n+1);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
}










