#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    int n; cin >> n;
    vector<int> nums(n);

    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int ans = 0;
    int mid = nums[n/2];

    for (auto e:nums) {
        if (e < mid) ans += mid - e;
        if (e > mid) ans += e - mid;
    }

    cout << ans << "\n";


    return 0;
}
