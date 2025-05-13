#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t, n, a, b;
    cin >> t;
	while(t--){
        cin >> n >> a >> b;
		for(int i = 0; i < n; i++) printf("%c", 97+i%b);
		cout << "\n";
	}
}
