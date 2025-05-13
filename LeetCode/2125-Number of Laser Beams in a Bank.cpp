#include <bits/stdc++.h>
#define ll long long

using namespace std;

int numberOfBeams(vector<string>& bank) {
    int n = bank.size();
    vector<int> A;
    for(int i = 0; i < n; i++){
        string str = bank[i];
        int m = str.size(), cnt = 0;
        for(int j = 0; j < m; j++)
            if(str[j] == '1') cnt++;
        if(cnt) A.push_back(cnt);
    }
    int ans = 0;
    if(A.size() <= 1) return ans;
    for(int i = 1; i < A.size(); i++) ans += A[i]*A[i-1];
    return ans;
}

int main()
{
    vector<string> bank(4);
    for(int i = 0; i < bank.size(); i++) cin >> bank[i];
    int ans = numberOfBeams(bank);
    cout << ans << "\n";
}

/**
011001 000000 010100 001000
*/
