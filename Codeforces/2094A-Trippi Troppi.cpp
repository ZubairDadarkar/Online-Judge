#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

string c_name;

void ReadCase();
void SolveCase();

int main() {
    int t;
    cin >> t;
    getchar();

    while(t--) {
        ReadCase();
        SolveCase();
    }

    return 0;
}

void ReadCase() {
    getline(cin, c_name);

}

void SolveCase() {
    string ans = "";
    ans += c_name[0];

    for(int i = 1; i < c_name.size(); i++) {
        if(c_name[i-1] == ' ') ans += c_name[i];
        if(ans.size() == 3) break;
    }

    cout << ans << "\n";
}
