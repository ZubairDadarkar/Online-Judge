#include <bits/stdc++.h>
#define ll long long

using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    for(int i = 0; i < nums.size(); i+=2)
        ans += min(nums[i], nums[i+1]);
    return ans;
}

int main()
{
    vector<int> nums(4);
    for(int i = 0; i < nums.size(); i++) cin >> nums[i];
    int ans = arrayPairSum(nums);
    cout << ans << "\n";
}
