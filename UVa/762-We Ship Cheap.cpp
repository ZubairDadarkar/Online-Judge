#include <bits/stdc++.h>
#define ll long long
#define MAX 200003

using namespace std;

int m, n;
map<string, int> M;
vector<int> graph[MAX];
vector<int> par(MAX, 0);
vector<string> names(MAX);

void inputsGraph();
int getId(string str);
void printsMap();
void BFS(int root);
void printsGraph();
void printsParent();
void printsPath(int v);

int main() {
//    freopen("762-We Ship Cheap_Input.txt", "r", stdin);
//    freopen("762-We Ship Cheap_Output.txt", "w", stdout);

    bool blankLine = false;
    while(cin >> m) {
        if(blankLine) cout << "\n";
        blankLine = true;

        inputsGraph();
//        printsMap();

        string A, B;
        cin >> A >> B;

        if(M.count(A) && M.count(B)) {
            int u, v;
            u = getId(A);
            v = getId(B);
            BFS(u);
            printsPath(v);
        }
        else cout << "No route\n";
    }

    return 0;
}

void printsPath(int v) {
    if(!par[v]) {
        cout << "No route\n";
        return;
    }

    vector<int> path;
    while(v != -1) {
        path.push_back(v);
        v = par[v];
    }

    reverse(path.begin(), path.end());
    for(int i = 1; i < path.size(); i++) {
        cout << names[ path[i-1] ].c_str() << " " << names[ path[i] ].c_str() << "\n";
    }
}

void BFS(int root) {
    queue<int> Q;
    par[root] = -1;
    Q.push(root);
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if(par[v]) continue;
            par[v] = u;
            Q.push(v);
        }
    }
//    cout << "\n";
//    printsGraph();
}

void inputsGraph() {
    M.clear();
    for(int i = 1; i <= 2*m; i++) graph[i].clear();
    par.clear(); par.resize(MAX, 0);

    n = 0;
    for(int i = 0; i < m; i++) {
        string A, B;
        cin >> A >> B;
        int u, v;
        u = getId(A); names[u] = A;
        v = getId(B); names[v] = B;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int getId(string str) {
    if(M.find(str) == M.end()) M[str] = ++n;
    return M[str];
}

//----------------------------------------------------------------------------------------

void printsMap() {
    for(auto s : M)
        cout << s.first << " " << s.second << "\n";
}

void printsGraph() {
    for(int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
    printsParent();
}

void printsParent() {
    for(int i = 1; i <= n; i++)
        cout << i << " -> " << par[i] << "\n";
    cout << "\n";
}

/**
3
JV PT
KA PT
KA HP
JV HP
2
JV PT
KA HP
JV HP
*/
