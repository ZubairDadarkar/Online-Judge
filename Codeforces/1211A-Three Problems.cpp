#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

vector<int> unique_nums;
unordered_map<int, int> num_to_idx;
int n;

void ReadCase();
void SolveCase();

int main() {
    ReadCase();
    SolveCase();

    return 0;
}

void ReadCase() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if(num_to_idx.find(num) != num_to_idx.end())
            continue;

        num_to_idx[num] = i+1;
        unique_nums.push_back(num);
    }
}

void SolveCase() {
    int len = unique_nums.size();
    if(len < 3) {
        cout << "-1 -1 -1\n";
        return;
    }

    sort(unique_nums.begin(), unique_nums.end());
    for(int i = 0; i < 3; i++) {
        cout << num_to_idx[unique_nums[i]] << " ";
    }
    cout << "\n";
}
