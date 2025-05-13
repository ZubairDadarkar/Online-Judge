#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--) {
        int leg;
        cin >> leg;
        cout << (leg / 4) + ((leg % 4) / 2) << "\n";
    }
}
