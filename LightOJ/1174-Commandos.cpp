#include <bits/stdc++.h>
#define ll long long
#define MAX 1003

using namespace std;

int n, r;
vector <int> graph[MAX];
vector <int> dis, dis2;
queue <int> Q;

void inputsGraph();
void BFS(int root);
void BFS2(int root);
void printsDis();
void printsDis2();

int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        inputsGraph();
        int s, d;
        cin >> s >> d;
        BFS(s);
        BFS2(d);

        int maxUnit = 0;
        for(int i = 0; i < n; i++) {
            maxUnit = max( maxUnit, (dis[i] + dis2[i]) );
        }
        cout << "Case " << i << ": " << maxUnit << "\n";
    }
}

void BFS(int root) {
    Q.push(root);
    dis[root] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if(dis[v] >= 0) continue;
            dis[v] = dis[u]+1;
            Q.push(v);
        }
    }
//    printsDis();
}

void BFS2(int root) {
    Q.push(root);
    dis2[root] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if(dis2[v] >= 0) continue;
            dis2[v] = dis2[u]+1;
            Q.push(v);
        }
    }
//    printsDis2();
}

void inputsGraph() {
    cin >> n >> r;

    for(int i = 0; i < n; i++) graph[i].clear();
    dis.clear(); dis.resize(n+1, -1);
    dis2.clear(); dis2.resize(n+1, -1);

    for(int i = 0; i < r; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void printsDis() {
    for(int i = 0; i < n; i++)
        cout << i << " -> " << dis[i] << "\n";
    cout << "\n";
}

void printsDis2() {
    for(int i = 0; i < n; i++)
        cout << i << " -> " << dis2[i] << "\n";
    cout << "\n";
}

/**
1
4
3
0 1
2 1
1 3
0 3

1
4
5
0 1
0 2
2 3
1 3
0 3
0 2
*/
