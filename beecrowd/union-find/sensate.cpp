#include <bits/stdc++.h>

using namespace std;

map<string, int> con;
vector<int> sz, group, ori, bigger, sens;

int fin(int p) {
    if (group[p] == p) return p;
    return group[p] = fin(group[p]);
}

void uni(int p, int q){
    int a = fin(p), b = fin(q);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    group[b] = a;
    sz[a] += sz[b];
    bigger[a] = max(bigger[a], bigger[b]);
}

int main() {
    int n, m, q; cin >> n >> m >> q;
    sz.assign(n, 1); group.resize(n); ori.resize(n);
    bigger.assign(n, 0); sens.assign(n, 0);

    for (int i=0; i<n; i++) {
        string name; int pw; cin >> name >> pw;
        con[name] = i;
        group[i] = i;
        ori[i] = bigger[i] = pw;
    }

    for (int i=0; i<m; i++) {
        string a, b; cin >> a >> b;
        uni(con[a], con[b]);
        sens[con[a]] = sens[con[b]] = 1;
    }

    for (int i=0; i<q; i++) {
        string ls; cin >> ls;
        if (!sens[con[ls]]) cout << "S\n";
        else if (ori[con[ls]] >= 5) cout << "S\n";
        else if (bigger[fin(con[ls])] <= 5) cout << "S\n";
        else cout << "N\n";
    }

    return 0; 
}