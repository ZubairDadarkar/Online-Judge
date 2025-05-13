#include <bits/stdc++.h>
#define ll long long
#define MAX 202

using namespace std;

int n;
vector<int> graph[MAX];
vector<string> strArr;
unordered_map<string, int> words;

void inputsWords();
int solveBFS(int root, int dest);
void createsGraph();
bool isAdjacentWords(string A, string B);

void printsWords();
void printsGraph();

int main() {
    freopen("429-Word Transformation_Input.txt", "r", stdin);
    freopen("429-Word Transformation_Output.txt", "w", stdout);

    int T; bool blankLine = false;
    cin >> T;
    getchar();
    while(T--) {
        if(blankLine) cout << "\n";
        blankLine = true;

        inputsWords();
//        printsWords();
//        cout << n << "\n";
        createsGraph();
//        printsGraph();
        getchar();
        string str;
        while( getline(cin, str) && str.compare("") ) {
            string startW = "", endW = "";

            int s;
            for(s = 0; str[s] != ' '; s++) startW += str[s];
            for(s = s+1; str[s] != '\0'; s++) endW += str[s];

            int root = words[startW];
            int dest = words[endW];
//            cout << root << " " << dest << "\n";
            int ans = solveBFS(root, dest);

            cout << startW << " " << endW << " " << ans << "\n";
        }
    }

    return 0;
}

int solveBFS(int root, int dest) {
    if(root == dest) return 0;
    queue<int> Q;
    vector<int> dis(n+1, -1);

    dis[root] = 0;
    Q.push(root);

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if(v == dest) return dis[u]+1;
            if(dis[v] != -1) continue;
            dis[v] = dis[u]+1;
            Q.push(v);
        }
    }

    return -1;
}

void inputsWords() {
    words.clear();
    strArr.clear();
    n = 0;

    string word;
    int id = 1;
    while(1) {
        cin >> word;
        if(word == "*") break;
        strArr.push_back(word);
        n++;
        words[word] = id++;
    }
//    printsWords();
}

void createsGraph() {
    for(int i = 1; i <= n; i++) graph[i].clear();

    for(int i = 0; i < strArr.size(); i++) {
        for(int j = i+1; j < strArr.size(); j++) {
            bool isAdj = isAdjacentWords(strArr[i], strArr[j]);
            if(isAdj) {
                int u = words[ strArr[i] ];
                int v = words[ strArr[j] ];

                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
    }
}

bool isAdjacentWords(string A, string B) {
    if(A.size() != B.size()) return false;
    int cnt = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] != B[i]) cnt++;
    }
    if(cnt == 1) return true;
    return false;
}

void printsWords() {
    for(auto str : words)
        cout << str.first << " " << str.second << "\n";
    cout << "\n";
}

void printsGraph() {
    for(int i = 1; i <= n; i++) {
        cout << i << " => ";
        for(int j = 0; j < graph[i].size(); j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

/**
1

axe
axi
bxi
cxi
dxi
dli
dlx
dls
cls
clx
*
axe axi
axe clx
axi cls
axi dli
dli cls
cxi cls
*/
