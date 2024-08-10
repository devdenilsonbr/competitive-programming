#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4;

vector<tuple<int, int, int>> fer;
vector<tuple<int, int, int>> rod;
int cities[maxn];
int sz[maxn];

int find(int p) {
    if (cities[p] == p) return p;
    return cities[p] = find(cities[p]);
}

void uni(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    cities[b] = a;
    sz[a] += sz[b];
}

int main() {
    int n, f, r; cin >> n >> f >> r;

    for (int i=1; i<=n; i++) {
        cities[i] = i;
        sz[i] = 1;
    }

    for (int i=0; i<f; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        fer.push_back({c, a, b});
    }
    for (int i=0; i<r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        rod.push_back({c, a, b});
    }

    sort(fer.begin(), fer.end());
    sort(rod.begin(), rod.end());
    int ans = 0;
    for (auto [a, b, c]:fer) {
        if (find(b) != find(c)) {
            ans += a;
            uni(b, c);
        }
    }
    for (auto [a, b, c]:rod) {
        if (find(b) != find(c)) {
            ans += a;
            uni(b, c);
        }
    }

    cout << ans << "\n";

    return 0;
}
