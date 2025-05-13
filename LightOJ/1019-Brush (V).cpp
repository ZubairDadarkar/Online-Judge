#include <bits/stdc++.h>
#define ll long long
#define MAX 202
#define INF INT_MAX

using namespace std;

struct Node {
    int node;
    int weight;

    Node() {}
    Node(int _node, int _weight) {
        node = _node;
        weight = _weight;
    }
};

int n, m;
vector<vector<int>> graph, weight;
vector<int> dis;

void graphInput();
int dijkstra(int);

int main() {
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        graphInput();
        int ans = dijkstra(1);

//        for(int i = 0; i <= n; i++) cout << dis[i] << " ";
//        cout << "\n";

        cout << "Case " << i << ": ";
        if(ans == INF) cout << "Impossible\n";
        else cout << ans << "\n";
    }
}

bool operator < (const Node &u, const Node &v) {
    return u.weight > v.weight;
}

int dijkstra(int root) {
    dis.clear(); dis.resize(n+1, INF);
    priority_queue<Node> pq;

    dis[root] = 0;
    pq.push({root, 0});

    while(!pq.empty()) {
        Node U = pq.top();
        pq.pop();

        int u = U.node;
        int uw = U.weight;

        if(dis[u] < uw) continue;

        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            int vw = weight[u][i];
            if(dis[u]+vw < dis[v]) {
                dis[v] = dis[u]+vw;
                pq.push({v, dis[v]});
            }
        }
    }

    return dis[n];
}

void graphInput() {
    cin >> n >> m;
    graph.clear(); graph.resize(n+1);
    weight.clear(); weight.resize(n+1);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(v); weight[u].push_back(w);
        graph[v].push_back(u); weight[v].push_back(w);
    }
}
