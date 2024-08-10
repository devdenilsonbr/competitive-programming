#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 1e6;

int nums[maxn];
int seg[maxn*4];

int build(int node, int l, int r) {
    if (r == l) {
        seg[node] = nums[l];
        return seg[node];
    }
    int mid = (l+r)/2;
    return seg[node] = build(node*2, l, mid) + build(node*2+1, mid+1, r);
}

void update(int node, int l, int r, int pos, int v) {
    if (l == r) {
        seg[node] = v;
        nums[pos] = v;
        return;
    }
    int mid = (r+l)/2;
    if (l <= pos && pos <= mid) update(node*2, l, mid, pos, v);
    else update(node*2+1, mid+1, r, pos, v);

    seg[node] = seg[node*2] + seg[node*2+1]; 
}

int con(int node, int cl, int cr, int l, int r) {
    if (cl > r || cr < l) return 0;
    if (cl >= l && cr <= r) return seg[node];
    int mid = (cl+cr)/2;
    return con(node*2, cl, mid, l, r) + con(node*2+1, mid+1, cr, l, r);
    // so consultar n preciso atualizar
}


int32_t main() {
    int n, q; cin >> n >> q;

    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    build(1, 0, n-1);

    for (int i=0; i<q; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 2) {
            a--; b--;
            cout << con(1, 0, n-1, a, b) << "\n";
        }
        else {
            a--;
            update(1, 0, n-1, a, b);
        }
    }

    return 0;
}
