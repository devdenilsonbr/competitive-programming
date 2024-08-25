#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4;

int cities[maxn];
int sz[maxn];

int find(int p) {
    if (cities[p] == p) return p;
    return cities[p] = find(cities[p]);
}

void uno(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    cities[b] = a;
    sz[a] += sz[b];
}

int main() {
    int n, k; cin >> n >> k;
    vector<tuple<int, int, int>> roads;

    for (int i=1; i<=n; i++) {
        cities[i] = i;
        sz[i] = 1;
    }

    for (int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        roads.push_back({c, a, b});
    }

    sort(roads.begin(), roads.end());

    int ans = 0;

    for (auto [a, b, c]:roads) {
        if (find(b) != find(c)) {
            uno(b, c);
            ans += a;
        }
    }

    cout << ans << "\n";


    return 0;
}
