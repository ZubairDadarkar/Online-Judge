#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		double p, q, x, y, ans;
		cin >> p >> x >> q >> y;
		ans = log10(p/q) + x-y;
		if(ans==0) cout<<"=\n";
		else if(ans>0) cout<<">\n";
		else cout<<"<\n";
	}
	return 0;
}
