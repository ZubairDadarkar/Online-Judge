#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        string subS = s.substr(0, n/2);
        if(subS+subS == s) cout << "YES\n";
        else cout << "NO\n";
    }
}
