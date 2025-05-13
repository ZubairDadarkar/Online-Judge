#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2){
            if(n == 1) cout << "1\n";
            else cout << "-1\n";
            continue;
        }
        for(int i = 2; i <= n; i+=2) cout << i << " " << i-1 << " ";
        cout << "\n";
    }
}
