#include <bits/stdc++.h>

using namespace std;

const int maxn = 32;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;
    int next[maxn][n+1];

    for (int i=1; i<=n; i++) {
        cin >> next[0][i];
    }

    for (int i=1; i<maxn; i++) {
        for (int k=1; k<=n; k++) {
            next[i][k] = next[i-1][next[i-1][k]];
        }
    }

    while (q--) {
        int x, k; cin >> x >> k;
        for (int i=0; i<maxn; i++) {
            if (k & (1 << i)) x = next[i][x];
        }
        cout << x << "\n";
    }

    return 0;
}
