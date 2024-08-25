#include <bits/stdc++.h>

using namespace std;

vector<int> city;
vector<int> sz;

int find(int p) {
    if (city[p] == p) return p;
    return city[p] = find(city[p]);
}

int best = 0;

void uni(int p, int q, int& t) {
    int a = find(p), b= find(q);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    city[b] = a;
    sz[a] += sz[b];
    best = max(best, sz[a]);
    t--;
}

int main() {
    int n, r; cin >> n >> r;
    city.resize(n+1);
    sz.resize(n+1, 1);

    for (int i=1; i<=n; i++) {
        city[i] = i;
    }

    int comp = n;

    for (int i=0; i<r; i++) {
        int a, b; cin >> a >> b;
        uni(a, b, comp);
        cout << comp << " " << best << "\n";
    }


    return 0;
}
