#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m, len;
        cin >> n;
        m = n/2;
        if(n%2) m++;
        cout << m << "\n";
        for(int i = 0; i < m; i++)
            cout << i*3+1 << " " << n*3-i*3 << "\n";
    }
}
