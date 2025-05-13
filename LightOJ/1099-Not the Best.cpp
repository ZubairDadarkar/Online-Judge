#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009
#define INF 50005

using namespace std;

int n, m;
vector<vector<pair<int, int>>> graph;

void intputGraph();
int dijkstraAlgo(int);

int main() {
    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        intputGraph();
        int ans = dijkstraAlgo(1);
        cout << "Case " << i << ": " << ans << "\n";
    }
}

int dijkstraAlgo(int root) {
    vector<int> dis1(n+1, INF), dis2(n+1, INF);
    priority_queue<pair<int, int>> pq;

    dis1[root] = 0;
    pq.push({0, root});

    while(!pq.empty()) {
        int u = pq.top().second;
        int uw = -pq.top().first;
        pq.pop();

        for(auto x : graph[u]) {
            int v = x.first;
            int w = x.second;

            if(dis1[v] > uw+w) {
                dis2[v] = dis1[v];
                dis1[v] = uw+w;
                pq.push({ -dis1[v], v });
            }
            else if(dis2[v] > uw+w && dis1[v] != uw+w) {
                dis2[v] = uw+w;
                pq.push({ -dis2[v], v });
            }
        }
    }

    return dis2[n];
}

void intputGraph() {
    cin >> n >> m;
    graph.clear(); graph.resize(n+1);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
}

