#include <bits/stdc++.h>

using namespace std;

vector<int> dp[5000];
int vis[5000];

vector<int> bestSum(int target, vector<int> nums) {
    if (vis[target]) return dp[target];
    if (target == 0) return {1};
    if (target < 0) return {};

    vector<int> best={};

    for (auto e:nums) {
        int remainder = target - e;
        vector<int> result = bestSum(remainder, nums);
        if (!result.empty()) {
            result.push_back(e);
            if (best.empty() || result.size() < best.size()) {
                best = result;
            }
        }
    }

    dp[target] = best;
    vis[target] = 1;
    return best;

}

int main() {
    vector<int> ans = bestSum(7, {4, 10, 6, 1, 2});

    for (auto e:ans) {
        cout << e << " ";
    }

    return 0;
}