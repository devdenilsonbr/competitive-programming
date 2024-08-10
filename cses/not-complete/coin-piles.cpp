#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 1e5+10;

bool vis[maxn];

bool piles(int a, int b) {
    if (a == 2 && b == 1) return 1;
    if (a == 1 && b == 2) return 1;
    if (a < 0 || b < 0) return 0;

    return piles(a-2, b-1) || piles(a-1, b-2);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        if (piles(a, b)) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}
