#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;


int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    int dots[maxn];
    int ranges[maxn];
    vector<pair<int, int>> o;
    cin >> n >> m;

    for (int i=1; i<n; i++) {
        cin >> ranges[i];
    }

    ranges[n] = INT_MAX;

    for (int i=1; i<=n; i++) {
        cin >> dots[i];
    }

    for (int i=1; i<=m; i++) {
        int b; cin >> b;
        o.push_back({b, i});
    }

    sort(o.begin(), o.end());

    int ans[maxn];

    for (int i=0, j=1; i<m;) {
        if (o[i].first < ranges[j]) {
            ans[o[i].second] = dots[j];
            i++;
        }
        else {
            j++;
        }
    }

    for (int i=1; i<=m; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
