#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e5+10;

vector<tuple<int, int, int>> roads;
int city[maxn];
int sz[maxn];

int find(int p) {
    if (city[p] == p) return p;
    return city[p] = find(city[p]);
}

void uni(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    city[b] = a;
    sz[a] += sz[b];
}

int32_t main() {
    int n, r; cin >> n >> r;

    for (int i=1; i<=n; i++) {
        city[i] = i;
        sz[i] = 1;
    }

    for (int i=0; i<r; i++) {
        int a, b, c; cin >> a >> b >> c;
        roads.push_back({c, a, b});
    }

    sort(roads.begin(), roads.end());

    int ans = 0;
    int t = n;
    for (const auto& [a, b, c] : roads) {
        if (find(b) != find(c)) {
            ans += a;
            t--;
            uni(b, c);
        }
    }

    if (t == 1) cout << ans << "\n";
    else cout << "IMPOSSIBLE\n";

    return 0;
}
