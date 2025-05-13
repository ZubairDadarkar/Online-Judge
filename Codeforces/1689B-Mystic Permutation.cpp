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
        vector<int> V(n+2);
        for(int i = 0, j = n+2; i < n+2; i++, j--) V[i] = j;
        vector<int> A(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        for(int i = 0; i < n-1; i++){
            int s = V.size();
            if(A[i] == V.back()) {
                A[i] = V[s-2];
                swap(V[s-1], V[s-2]);
            }
            else A[i] = V.back();
            V.pop_back();
        }
        if(n == 1) {
            cout << "-1\n";
            continue;
        }
        if(A[n-1] == V.back()) swap(A[n-1], A[n-2]);
        else A[n-1] = V.back();
        for(int i = 0; i < n; i++) cout << A[i] << " ";
        cout << "\n";
    }
}
