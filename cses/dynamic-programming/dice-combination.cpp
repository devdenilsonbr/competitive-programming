#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> num={1, 2, 3, 4, 5, 6};
int dp[1000010];
bool vis[1000010];
const int r = 1e9+7;

int dice(int n) {
    int count=0;

    if (vis[n]) return dp[n];
    if (n == 0) return 1;
    if (n < 0) return 0;

    for (auto e:num) {
        int remainder = n - e;
        count = (count+dice(remainder))%r;
    }
    dp[n] = count;
    vis[n] = 1;
    return dp[n];
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    int ans=dice(n);

    
    cout << ans << "\n";

    return 0;
}
