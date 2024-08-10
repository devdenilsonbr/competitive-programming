#include <iostream>


using namespace std;

const int maxn = 1000;

bool vis[maxn][maxn]={0};
long long dp[maxn][maxn];

long long grid(int n,int m) {
    if (n == 1 && m == 1) return 1;
    if (n == 0 || m == 0) return 0;
    if (vis[n][m] || vis[m][n]) return dp[n][m];
    vis[n][m] = vis[m][n] = 1;
    dp[n][m] = dp[m][n] = grid(n-1, m) + grid(n, m-1);
    return dp[n][m];
}

int32_t main() {


    cout << grid(2, 3) << "\n";
    cout << grid(3, 2) << "\n";
    cout << grid(3, 3) << "\n";
    cout << grid(4, 4) << "\n";
    cout << grid(18, 18) << "\n";
    cout << grid(25, 25) << "\n";


    return 0;
}