#include <bits/stdc++.h>
#define ll long long

using namespace std;

int thirdMax(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> arr;
    for(int i = n-1; i >= 0; i--) {
        if(arr.empty())
            arr.push_back(nums[i]);
        else if((nums[i] != arr.back()))
            arr.push_back(nums[i]);
        if(arr.size() == 3)
            return arr.back();
    }
    return nums.back();
}

int main()
{
    vector<int> nums;
    for(int i = 0; i < 3; i++) cin >> nums[i];
    int ans = thirdMax(nums);
    cout << ans << "\n";
}

/**
3 2 1
*/
