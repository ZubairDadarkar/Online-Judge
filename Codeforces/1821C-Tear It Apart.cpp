#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

string s;

void ReadCase() {
    cin >> s;
}

int GetAns(char ch) {
    int max_cnt = -1, cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ch) {
            max_cnt = max(max_cnt, cnt);
            cnt = 0;
        }
        else cnt++;
    }

    max_cnt = max(max_cnt, cnt);

    int res = 0;
    while(max_cnt) {
        res++;
        int sub = max_cnt/2;
        if(max_cnt%2) sub++;
        max_cnt -= sub;
    }

    return res;
}

int SolveCase() {
    int ans = INT_MAX;
    for(int i = 'a'; i <= 'z'; i++) {
        ans = min(ans, GetAns(i));
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while(t--) {
        ReadCase();
        cout << SolveCase() << "\n";
    }

    return 0;
}

/**
1
abacaba

*/

