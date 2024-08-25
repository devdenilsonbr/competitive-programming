#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e3;

int nums[maxn];
int dp[maxn];
bool vis[maxn];
int r = 1e9+7, n;

int coin(int num) {
    int cont = 0;

    if (vis[num]) return dp[num];
    if (num == 0) return 1;
    if (num < 0) return 0;


    for (int i=1; i<=n; i++) {
        int remainder = num - nums[i];
        cont = (cont + coin(remainder))%r;
    }
    dp[num] = cont;
    vis[num] = 1;
    return dp[num]; 
}

int32_t main() {
    int sum; cin >> n >> sum;

    for (int i=1; i<=n; i++) {
        cin >> nums[i];
    } 

    cout << coin(sum) << "\n";

    return 0;
}
