#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool is_first;
string line;

unordered_map<char, int> nodes_char_to_i;
unordered_map<int, char> nodes_i_to_char;
int node_id;

vector<vector<int>> adj_list;

void ReadCase();

void PrintAdjList();

int main() {
    freopen("input.txt", "r", stdin);
    is_first = true;

    while(getline(cin, line)) {
        ReadCase();
    }
}

void ReadCase() {
    nodes_char_to_i.clear();
    nodes_i_to_char.clear();
    node_id = 0;

    for(char& ch : line) {
        if(ch == ' ') continue;
        nodes_char_to_i[ch] = node_id;
        nodes_i_to_char[node_id] = ch;
        node_id++;
    }

    adj_list.clear();
    adj_list.resize(node_id);

    getline(cin, line);
    for(int i = 0; i < line.size(); i++) {
        if(line[i] == ' ') i++;
        int u = nodes_char_to_i[line[i]];

        i++;

        if(line[i] == ' ') i++;
        int v = nodes_char_to_i[line[i]];

        adj_list[u].push_back(v);
    }

//    PrintAdjList();
}

void PrintAdjList() {
    for(auto& [ch, i] : nodes_char_to_i) {
        cout << ch << " -> " << i << "\n";
    }
    cout << "\n";

    for(auto& [i, ch] : nodes_i_to_char) {
        cout << i << " -> " << ch << "\n";
    }
    cout << "\n";

    for(int u = 0; u < node_id; u++) {
        cout << nodes_i_to_char[u] << " -> ";
        for(int v : adj_list[u]) {
            cout << nodes_i_to_char[v] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
