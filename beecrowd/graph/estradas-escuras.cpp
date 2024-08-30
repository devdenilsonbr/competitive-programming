#include <bits/stdc++.h>

using namespace std;

vector<int> sz;
vector<int> roads;
vector<tuple<int, int, int>> rd;

int fin(int p) {
    if (roads[p] == p) return p;
    return roads[p] = fin(roads[p]);
}

void uni(int p, int q) {
    int a = fin(p), b = fin(q);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    roads[b] = a;
    sz[a] += sz[b];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, e;

    while (cin >> n >> e) {
        if (n == 0 && e == 0) break;
        roads.resize(n);
        sz.assign(n, 1);

        for (int i=0; i<n; i++) {
            roads[i] = i;
        }
        int tot=0;
        for (int i=0; i<e; i++) {
            int a, b, c; cin >> a >> b >> c;
            rd.push_back({c, a, b});
            tot += c;
        }
        sort(rd.begin(), rd.end());
        int ans = 0;
        for (auto [a, b, c]:rd) {
            if (fin(b) != fin(c)) {
                ans += a;
                uni(b, c);
            }
        }

        cout << tot - ans << "\n";
        rd.clear();

    }


    return 0;
}