#include <bits/stdc++.h>

#define int long long

using namespace std;

bool dp[1050][100010];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, t; cin >> n >> t;
    int num[1050];
    memset(dp, 0, sizeof(dp));
    memset(num, 0, sizeof(num));
    dp[0][0] = 1;

    for (int i=1; i<=t; i++) {
        int a; cin >> a;
        dp[i][0] = 1;
        num[i] = a;
    }
     
    for (int i=1; i<=t; i++) {
        for (int j=1; j<=n; j++) {
            if (j < num[i]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-num[i]];
            }
            if (dp[i][j]) cout << j << " ";// o j é todas as somas possiveis
        }
    }
    cout << "\n";

    if (dp[t][n]) cout << "S\n";
    else cout << "N\n";    
    
    return 0;
}