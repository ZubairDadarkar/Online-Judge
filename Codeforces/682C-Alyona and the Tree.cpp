/*
#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
vector<int> a;
vector<vector<pair<int, int>>> tree;

void InputTree();
int BFS(int);

int main() {
    cin >> n;
    a.clear(); a.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    InputTree();
    int ans = BFS(1);
    cout << ans << "\n";
    return 0;
}

int BFS(int root) {
    vector<bool> mark(n+1, false);
    queue<pair<int, int>> q;
    int cnt = 0;

    q.push({root, 0});
    mark[root] = true;

    while(!q.empty()) {
        int u, ud;
        tie(u, ud) = q.front();
        q.pop();
        cnt++;

        for(int i = 0; i < tree[u].size(); i++) {
            int v, vd;
            tie(v, vd) = tree[u][i];
            if(ud+vd > a[v]) continue;
            mark[v] = true;
            q.push({v, ud+vd});
        }
    }

    return n-cnt;
}

void InputTree() {
    tree.clear(); tree.resize(n+1);

    for(int i = 2; i <= n; i++) {
        int u, c;
        cin >> u >> c;
        tree[u].push_back({i, c});
    }
}
//*/

///*
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<pair<int, int>>> tree;

void InputTree();
int DFS(int, int);


int main() {
    cin >> n;
    a.clear(); a.resize(n+1);

    for(int i = 1; i <= n; i++) cin >> a[i];

    InputTree();
    cout << n-DFS(1, 0) << "\n";

    return 0;
}

int DFS(int u, int ud) {
    int cnt = 0;
    if(ud > a[u]) return 0;

    for(int i = 0; i < tree[u].size(); i++) {
        int v, vd;
        tie(v, vd) = tree[u][i];
        cnt += DFS(v, max(0, ud+vd));
    }

    return cnt+1;
}


void InputTree() {
    tree.clear(); tree.resize(n+1);

    for(int i = 2; i <= n; i++) {
        int u, c;
        cin >> u >> c;
        tree[u].push_back({i, c});
    }
}
//*/


