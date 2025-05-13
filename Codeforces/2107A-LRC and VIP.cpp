#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
int min_val, max_val;
vector<int> arr;

void InitCase();
void ReadCase();
void SolveCase();
void PrintCase();

int main() {
    int t;
    cin >> t;

    while(t--) {
        InitCase();
        ReadCase();
        SolveCase();
        PrintCase();
    }

    return 0;
}

void InitCase() {
    arr.clear();
    min_val = INT_MAX;
    max_val = INT_MIN;
}

void ReadCase() {
    cin >> n;
    arr.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
    }
}

void SolveCase() {
    if(min_val == max_val) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        if(arr[i] == max_val) {
            cout << "1";
        }
        else {
            cout << "2";
        }
        cout << " ";
    }
    cout << "\n";
}

void PrintCase() {

}

