#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> partitionLabels(string s) {
    unordered_map<char, int> lastIndex;
    for(int i = 0; i < s.size(); i++) lastIndex[s[i]] = i;
    vector<int> ans;
    int prev = -1;
    int maxi = 0;
    for(int i = 0; i < s.size(); i++) {
        maxi = max(maxi, lastIndex[s[i]]);
        if(i == maxi) {
            ans.push_back(i - prev);
            prev = maxi;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<int> ans = partitionLabels(s);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
}
