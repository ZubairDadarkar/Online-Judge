#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int maxVal = 0, minVal = INT_MAX, val;
        for(int i = 0; i < n; i++){
            cin >> val;
            if(val < minVal) minVal = val;
            if(val > maxVal) maxVal = val;
        }
        cout << maxVal-minVal << "\n";
    }
}
