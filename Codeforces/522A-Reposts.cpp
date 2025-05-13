#include <bits/stdc++.h>
#include <iostream>
#include <string>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
vector<vector<int>> tree;
unordered_map<string, int> m;
vector<int> lev;

void InputTree();
int BFS(int);
pair<string, string> GetNames(string);

int main() {
    cin >> n;
    getchar();

    InputTree();

    int root = m["polycarp"];
    int ans = BFS(root);
    cout << ans << "\n";

    return 0;
}

int BFS(int root) {
    lev.clear(); lev.resize(n+2, 0);
    queue<int> q;

    q.push(root);
    lev[root] = 1;

    int u;
    while(!q.empty()) {
        u = q.front();
        q.pop();

        for(int i = 0; i < tree[u].size(); i++) {
            int v = tree[u][i];
            if(lev[v]) continue;
            lev[v] = lev[u]+1;
            q.push(v);
        }
    }

    return lev[u];
}

void InputTree() {
    tree.clear(); tree.resize(n+2);
    int id = 1;

    for(int i = 0; i < n; i++) {
        string str;
        getline(cin, str);

        string name_a, name_b;
        tie(name_a, name_b) = GetNames(str);

        if(!m.count(name_a)) m[name_a] = id++;
        if(!m.count(name_b)) m[name_b] = id++;

        int v = m[name_a], u = m[name_b];

        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}

pair<string, string> GetNames(string str) {
    vector<string> words;
    string word;
    stringstream line(str);

    while(getline(line, word, ' ')) {
        words.push_back(word);
    }

    string name_a = words[0], name_b = words[2];

    for(auto& ch : name_a) ch = tolower(ch);
    for(auto& ch : name_b) ch = tolower(ch);

    return { name_a, name_b };
}










