#include <bits/stdc++.h>
#define ll long long
#define INF 1e9

using namespace std;

int n;
vector<vector<pair<int, int>>> graph;
vector<int> dis;
vector<bool> status;

void InputGraph();
int DijkstraAlgo(int);

int main() {
    int test_case; cin >> test_case;
    for(int i = 1; i <= test_case; i++) {
        InputGraph();
        int farthest_node = DijkstraAlgo(0);
        farthest_node = DijkstraAlgo(farthest_node);
        cout << "Case " << i << ": " << dis[farthest_node] << "\n";
    }
}

int DijkstraAlgo(int root) {
    dis.clear(); dis.resize(n, INF);
    status.clear(); status.resize(n, false);
    queue<pair<int, int>> q;

    int max_cost = -INF;
    int farthest_node;

    dis[root] = 0;
    q.push({root, 0});

    while(!q.empty()) {
        int u, c;
        tie(u, c) = q.front();
        if(c > max_cost) {
            farthest_node = u;
            max_cost = c;
        }
        q.pop();

        if(status[u]) continue;
        status[u] = true;

        for(auto node : graph[u]) {
            int v, w;
            tie(v, w) = node;
            if(dis[u]+w < dis[v]) {
                dis[v] = c+w;
                q.push({v, dis[v]});
            }
        }
    }

    return farthest_node;
}

void InputGraph() {
    cin >> n;
    graph.clear(); graph.resize(n);

    for(int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
}
