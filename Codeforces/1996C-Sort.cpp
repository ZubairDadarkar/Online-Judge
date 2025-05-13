#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;
        while(q--) {
            int l, r;
            cin >> l >> r;
            string subStrA = a.substr(l-1, r-l+1);
            string subStrB = b.substr(l-1, r-l+1);
            vector<int> A(26, 0), B(26, 0);
            for(int i = 0; i < subStrA.size(); i++) A[ subStrA[i]-'a' ]++;
            for(int i = 0; i < subStrB.size(); i++) B[ subStrB[i]-'a' ]++;
            int cnt = 0;
            for(int i = 0; i < 26; i++) {
                if(A[i] < B[i]) cnt += (B[i] - A[i]);
            }
            cout << cnt << "\n";
        }
    }
}
