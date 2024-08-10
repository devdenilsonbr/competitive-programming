#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;

vector<int> nums;
int dp[maxn];
bool vis[maxn];
int r = 1e9+7;

int coin(int num) {
    if (vis[num]) return dp[num];
    if (num == 0) return 1;
    if (num < 0) return 0;

    long long cont=0;

    for (auto e:nums) {
        int remainder = num - e;
        cont += (coin(remainder))%r;
    }
    dp[num] = cont;
    vis[num] = 1;
    return dp[num]; 
}

int32_t main() {
    int n, sum; cin >> n >> sum;

    for (int i=0; i<n; i++) {
        int a; cin >> a;
        nums.push_back(a);
    } 


    long long ans = coin(sum);

    cout << ans << "\n";

    return 0;
}
