#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    int n; cin >> n;
    vector<int> ans;

    for (int i=0; i<n; i++) {
        int sum, t, moves=0, bigger=0; cin >> sum >> t;
        vector<int> nums(t);

        for (int i=0; i<t; i++) {
            cin >> nums[i];
            bigger = max(nums[i], bigger);
        }
        int control=0;
        for (auto e:nums) {
            if (e != 1 && e != bigger) {
                moves += e-1;
            }
        }
        for (auto e:nums) {
            if (e == bigger) control++;
        }
        if (control > 1) {
            moves += (control-1) * (bigger-1);
        }
        moves += sum - bigger;
        ans.push_back(moves);
    }

    for (auto e:ans) {
        cout << e << "\n";
    }

    return 0;
}