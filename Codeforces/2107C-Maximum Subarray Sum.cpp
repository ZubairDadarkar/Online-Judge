#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

ll n, k;
string s;
vector<ll> nums;

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
    nums.clear();
}

void ReadCase() {
    cin >> n >> k;
    nums.resize(n);

    cin >> s;

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
}

void SolveCase() {
    vector<int> missing_idx;

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            missing_idx.push_back(i);
        }
    }

    ll max_subarr_sum = LLONG_MIN;
    ll curr_sum = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            nums[i] = -1e18;
        }

        curr_sum += nums[i];
        max_subarr_sum = max(max_subarr_sum, curr_sum);
        curr_sum = max(0LL, curr_sum);
    }

    if(max_subarr_sum > k) {
        cout << "NO\n";
        return;
    }

    if(max_subarr_sum == k) {
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
        return;
    }

    if(missing_idx.size() == 0) {
        cout << "NO\n";
        return;
    }

    ll max_sum_left = 0;
    for(int i = 0; i < missing_idx[0]; i++) {
        max_sum_left += nums[i];
        max_sum_left = max(0LL, max_sum_left);
    }

    ll max_sum_right = 0;
    for(int i = n-1; i > missing_idx[0]; i--) {
        max_sum_right += nums[i];
        max_sum_right = max(0LL, max_sum_right);
    }

//    cout << max_sum_left << " " << max_sum_right << "\n";
    nums[missing_idx[0]] = k - (max_sum_left + max_sum_right);

    cout << "YES\n";
    for(ll& num : nums) {
        cout << num << " ";
    }
    cout << "\n";
}

void PrintCase() {

}


