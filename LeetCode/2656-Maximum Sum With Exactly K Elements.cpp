#include <bits/stdc++.h>
#define ll long long

using namespace std;

int maximizeSum(vector<int>& nums, int k) {
    int maxVal = nums[0];
    for(int i = 1; i < nums.size(); i++)
        maxVal = max(maxVal, nums[i]);
    int ans = 0;
    for(int i = 0; i < k; i++) ans += maxVal+i;
    return ans;
}

int main()
{
    vector<int> nums(5);
    int k;
    for(int i = 0; i < nums.size(); i++) cin >> nums[i];
    cin >> k;
    int ans = maximizeSum(nums, k);
    cout << ans << "\n";
}
