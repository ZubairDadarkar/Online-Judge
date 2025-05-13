#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
vector<int> arr;

void ReadCase();
void SolveCase();

int main() {
    int t;
    cin >> t;

    while(t--) {
        ReadCase();
        SolveCase();
    }

    return 0;
}

void ReadCase() {
    cin >> n;

    arr.clear();
    arr.resize(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];
}

void SolveCase() {
    vector<int> freq(n+1, 0);
    for(int& v : arr)
        freq[v]++;

    vector<int> len(n, 0);
    len[0] = (freq[arr[0]] == 1);

    for(int i = 1; i < n; i++) {
        if(freq[arr[i]] == 1)
            len[i] = len[i-1] + 1;
    }

    int max_val = *max_element(len.begin(), len.end());
    if(max_val == 0) {
        cout << "0\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        if(len[i] == max_val) {
            cout << i-len[i] + 2 << " " << i+1 << "\n";
            return;
        }
    }
}
