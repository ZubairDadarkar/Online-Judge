#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> graph[30];
vector<int> dis;

void printsGraph();
void BFS(int root);
void printsDis();

int main() {
//    freopen("567-Risk_Input.txt", "r", stdin);
//    freopen("567-Risk_Output.txt", "w", stdout);

    int testSet = 1;

    while(1) {
        for(int i = 1; i <= 20; i++) graph[i].clear();

        for(int u = 1; u <= 19; u++) {
            int x; cin >> x;
            for(int i = 0; i < x; i++) {
                int v; cin >> v;
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
//        printsGraph();

        cout << "Test Set #" << testSet++ << "\n";

        int n; cin >> n; /// cout << "------------" << n << "--------------\n";
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
//            cout << a << " " << b << "\n";
            dis.clear(); dis.resize(21, -1);
            BFS(a);
//            printsDis();
            cout << a << " to " << b << ": " << dis[b] << "\n";
        }
        cout << "\n";
    }

    return 0;
}

void BFS(int root) {
//    cout << "In BFS\n"; printsDis();
    queue<int> Q;
    dis[root] = 0;
    Q.push(root);
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if(dis[v] != -1) continue;
            dis[v] = dis[u]+1;
            Q.push(v);
        }
    }
}

void printsGraph() {
    for(int i = 1; i <= 20; i++) {
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void printsDis() {
    for(int i = 1; i <= 20; i++) {
        cout << i << " -> " << dis[i] << "\n";
    }
    cout << "\n";
}

/**
1 3
2 3 4
3 4 5 6
1 6
1 7
2 12 13
1 8
2 9 10
1 11
1 11
2 12 17
1 14
2 14 15
2 15 16
1 16
1 19
2 18 19
1 20
1 20
5
1 20
2 9
19 5
18 19
16 20
4 2 3 5 6
1 4
3 4 10 5
5 10 11 12 19 18
2 6 7
2 7 8
2 9 10
1 9
1 10
2 11 14
3 12 13 14
3 18 17 13
4 14 15 16 17
0
0
0
2 18 20
1 19
1 20
6
1 20
8 20
15 16
11 4
7 13
2 16

*/
