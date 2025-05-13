#include <bits/stdc++.h>
#define ll long long

using namespace std;

string a, b;

int findPosition(int posi, char ch) {
    int i;
    for(i = posi; i < a.size(); i++) {
        if(a[i] == ch) break;
    }
    return i;
}

int main()
{
    int n;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        int posi = -1, ans = a.size(), cnt = 0;
        bool flag = false;
        for(int i = 0; i < b.size(); i++) {
            posi = findPosition(!flag ? 0 : posi+1, b[i]);
            if(posi < a.size()) flag = true;
            else {
                if(!flag) ans++;
                else {
                    ans += (b.size() - i);
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}
