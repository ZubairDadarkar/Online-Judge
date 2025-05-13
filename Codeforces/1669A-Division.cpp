#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int rating;

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
    cin >> rating;
}

void SolveCase() {
    if(1900 <= rating)
        cout << "Division 1\n";
    else if(1600 <= rating && 1899 >= rating)
        cout << "Division 2\n";
    else if(1400 <= rating && 1599 >= rating)
        cout << "Division 3\n";
    else
        cout << "Division 4\n";
}
