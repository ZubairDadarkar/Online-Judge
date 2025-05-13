#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
string cards;
vector<int> A, B;

void InitCase();
void ReadCase();
void SolveCase();

int main() {
    int t;
    cin >> t;

    while(t--) {
        InitCase();
        ReadCase();
        SolveCase();
    }

    return 0;
}

void InitCase() {
    A.clear();
    B.clear();
}

void ReadCase() {
    cin >> n;
    cin >> cards;
}

void SolveCase() {
    if(n == 2) {
        if(cards[0] == 'A') cout << "Alice\n";
        else cout << "Bob\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        if(cards[i] == 'A') A.push_back(i+1);
        else B.push_back(i+1);
    }

    if(cards[0] == cards[n-1]) {
        if(cards[0] == 'A') cout << "Alice\n";
        else cout << "Bob\n";
        return;
    }

    int a_len = A.size();
    int b_len = B.size();

    if(a_len == 1) {
        cout << "Bob\n";
        return;
    }
    if(b_len == 1) {
        cout << "Alice\n";
        return;
    }

    if(cards[n-1] == 'B' && b_len > 0) {
        cout << "Bob\n";
        return;
    }

    if(cards[n-1] == 'A') {
        if(cards[n-2] == 'A') cout << "Alice\n";
        else cout << "Bob\n";
    }
}
