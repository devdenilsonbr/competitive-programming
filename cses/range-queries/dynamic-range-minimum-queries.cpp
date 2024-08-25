#include <bits/stdc++.h>
#define inf 99999999999;
#define int long long

using namespace std;

vector<int> nums, seg;

int build(int node, int l, int r) {
    if (r == l) return seg[node] = nums[l];
    int mid = (r+l)/2;
    return seg[node] = min(build(node*2, l, mid), build(node*2+1, mid+1, r));
}

void update(int node, int l, int r, int x, int v) {
    if (l == r) {
        seg[node] = nums[x] = v;
        return;
    }
    int mid = (l+r)/2;
    if (x >= l && x <= mid) update(node*2, l, mid, x, v);
    else if (x > mid && x <= r) update(node*2+1, mid+1, r, x, v);
    seg[node] = min(seg[node*2], seg[node*2+1]);

}

int query(int node, int l, int r, int a, int b) {
    if (l > b || r < a) return inf;
    if (l >= a && r <= b) return seg[node];
    int mid = (l+r)/2;
    return min(query(node*2, l, mid, a, b), query(node*2+1, mid+1, r, a, b));
}

int32_t main() {

    int n, k; cin >> n >> k;
    nums.resize(n); seg.resize(n*4);

    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    build(1, 0, n-1);

    for (int i=0; i<k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            b--; update(1, 0, n-1, b, c);
        }
        else {
            b--; c--;
            cout << query(1, 0, n-1, b, c) << "\n";
        }
    }


    return 0;
}
