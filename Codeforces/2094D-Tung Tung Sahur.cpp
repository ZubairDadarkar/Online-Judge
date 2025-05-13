#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

string p, s;

void ReadCase();
void SolveCase();

int main() {
    int t;
    cin >> t;

    while(t--) {
        ReadCase();
        SolveCase();
    }

    return 0;
}

void ReadCase() {
    cin >> p >> s;
}

//void PrintDrumInfo(vector<pair<char, int>>& drum_cnt) {
//    for(auto& [drum, cnt] : drum_cnt) {
//        cout << drum << " " << cnt << "\n";
//    }
//}

void SolveCase() {
    int p_len = p.size();
    int s_len = s.size();

    vector<pair<char, int>> drum_cnt;

    char curr_drum = p[0];
    int curr_cnt = 1;

    for(int i = 1; i < p_len; i++) {
        if(p[i-1] != p[i]) {
            drum_cnt.push_back({curr_drum, curr_cnt});

            curr_drum = p[i];
            curr_cnt = 1;

            continue;
        }

        curr_cnt++;
    }
    drum_cnt.push_back({curr_drum, curr_cnt});

//    PrintDrumInfo(drum_cnt);
//    cout << "-----------------\n";

    vector<pair<char, int>> drum_cnt_s;

    curr_drum = s[0];
    curr_cnt = 1;

    for(int i = 1; i < s_len; i++) {
        if(s[i-1] != s[i]) {
            drum_cnt_s.push_back({curr_drum, curr_cnt});

            curr_drum = s[i];
            curr_cnt = 1;

            continue;
        }

        curr_cnt++;
    }
    drum_cnt_s.push_back({curr_drum, curr_cnt});

//    PrintDrumInfo(drum_cnt_s);

    int n = drum_cnt.size();
    int m = drum_cnt_s.size();

    if(n != m) {
        cout << "NO\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        char curr_p = drum_cnt[i].first;
        char curr_s = drum_cnt_s[i].first;

        if(curr_p != curr_s) {
            cout << "NO\n";
            return;
        }

        int cnt_p = drum_cnt[i].second;
        int cnt_s = drum_cnt_s[i].second;

        if(!(cnt_s >= cnt_p && cnt_s <= 2*cnt_p)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}
