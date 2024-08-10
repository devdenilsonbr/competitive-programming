#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 1e6;
const int inf = 1e12;

int nums[maxn];
int tree[maxn];

int build(int node, int l, int r) {
    if (l == r) {
        tree[node] = nums[l];
        return tree[node];
    }

    int mid = (l+r) / 2;

    return tree[node] = min(build(node*2, l, mid), build(node*2+1, mid+1, r));

}

int travel(int node, int cl, int cr, int l, int r) {
    if (cl > r || cr < l) return inf; 
    if (cl >= l && cr <= r) return tree[node];

    int mid = (cr+cl) / 2;

    return min(travel(node*2, cl, mid, l, r), travel(node*2+1, mid+1, cr, l, r));
}

int32_t main() {
    int n, q; cin >> n >> q;

    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    build(1, 0, n-1);


    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << travel(1, 0, n-1, a, b) << "\n";
    }

    return 0;
}