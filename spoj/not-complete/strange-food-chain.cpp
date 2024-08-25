#include <bits/stdc++.h>
#define maxn 200000

using namespace std;

int animals[maxn];
int sz[maxn];

int find(int node) {
    if(animals[node] == node) return node;
    return animals[node] = find(animals[node]);
}

void uno(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    animals[b] = a;
    sz[a] += sz[b];
}

int main() {
    int t; cin >> t;

    for (int i=0; i<t; i++) {
        int n, k; cin >> n >> k;
        for (int i=1; i<=n; i++) {
            animals[i] = i;
            sz[i] = 1;
        }

        int ans = 0;

        for (int i=0; i<k; i++) {
            int a, b, c; cin >> a >> b >> c;
            if (c > n || b > n) ans++;
        }
    }



    return 0;
}