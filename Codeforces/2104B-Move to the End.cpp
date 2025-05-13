#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
vector<ll> nums;
vector<ll> prefix_max;
vector<ll> suffix_sum;

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
    nums.clear();
    prefix_max.clear();
    suffix_sum.clear();
}

void ReadCase() {
    cin >> n;

    nums.resize(n);
    prefix_max.resize(n+1, 0LL);
    suffix_sum.resize(n+1, 0LL);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
}

void SolveCase() {
    ll curr_max = 0;
    for(int i = 0; i < n; i++) {
        curr_max = max(curr_max, nums[i]);
        prefix_max[i] = curr_max;
    }

    suffix_sum[n-1] = nums[n-1];
    for(int i = n-2; i >= 0; i--) {
        suffix_sum[i] = nums[i] + suffix_sum[i+1];
    }

//    for(auto num : prefix_max) cout << num << " ";
//    cout << "\n";
//
//    for(auto num : suffix_sum) cout << num << " ";
//    cout << "\n";

    vector<ll> ans;

    for(int i = n-1; i >= 0; i--) {
        ll p_max = prefix_max[i];
        ll s_sum = suffix_sum[i+1];

        ans.push_back(s_sum + p_max);
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
