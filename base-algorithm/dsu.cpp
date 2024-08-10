#include <iostream>

using namespace std;

const int maxn = 1e5;

int sets[maxn], sz[maxn];
int ans;

int find(int p) {
    if (sets[p] == p) return p;
    return sets[p] = find(sets[p]);
}

void uno(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;
    if (sz[a] > sz[b]) {
        sets[b] = a;
        sz[a] += sz[b];
    }
    else {
        sets[a] = b;
        sz[b] += sz[a];
    }

    ans--;

}



int main() {
    int n, r; cin >> n >> r;
    ans = n;

    for (int i=1; i<=n; i++) {
        sets[i] = i;
        sz[i] = 1;
    }
    

    for (int i=0; i<r; i++) {
        int a, b; cin >> a >> b;
        uno(a, b);
    }

    cout << ans << "\n";

    return 0;
}
