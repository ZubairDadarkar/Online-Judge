#include <bits/stdc++.h>
#define ll long long
#define MAX 100000009

using namespace std;

int n;
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

int LowerBound(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while(left < right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] < target) left = mid + 1;
        else right = mid;
    }

    return left;
}

void InitCase() {
    arr.clear();
}

void ReadCase() {
    cin >> n;
    arr.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void SolveCase() {
    int med = n / 2;
    if(n%2 == 0) med--;

    int a = arr[0];

    sort(arr.begin(), arr.end());

    if(arr[med] == a) {
        cout << "YES\n";
        return;
    }

    int a_idx = LowerBound(arr, a);
//    int neg_cnt = LowerBound(arr, 1);
//    int posi_cnt = n - neg_cnt;

    if(a_idx < med) {
        if(a >= 0) {
            cout << "YES\n";
            return;
        }
        else {
            int diff = med - a_idx;
            int x = LowerBound(arr, -a);
            if(diff <= n-x) {
                cout << "YES\n";
                return;
            }
        }
    }
    else {
        if(a < 0) {
            cout << "YES\n";
            return;
        }
        else {
            int diff = a_idx - med;
            int x = LowerBound(arr, -a);
            if(diff <= x) {
                cout << "YES\n";
                return;
            }
        }
    }

    a = -a;
    a_idx = LowerBound(arr, a) - 1;

    if(a_idx < med) {
        if(a >= 0) {
            cout << "YES\n";
            return;
        }
        else {
            int diff = med - a_idx;
            int x = LowerBound(arr, -a);
            if(diff <= n-x) {
                cout << "YES\n";
                return;
            }
        }
    }
    else {
        if(a < 0) {
            cout << "YES\n";
            return;
        }
        else {
            int diff = a_idx - med;
            int x = LowerBound(arr, -a);
            if(diff <= x) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";

}

void PrintCase() {

}

