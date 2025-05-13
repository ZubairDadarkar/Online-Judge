#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        if(nums[0] == 1) nums[0]++;
        for(int i = 1; i < n; i++) {
            if(nums[i] == 1) nums[i]++;
            if(nums[i-1] <= nums[i] && nums[i]%nums[i-1] == 0) nums[i]++;
        }
        for(int i = 0; i < n; i++) cout << nums[i] << " ";
        cout << "\n";
    }
}
