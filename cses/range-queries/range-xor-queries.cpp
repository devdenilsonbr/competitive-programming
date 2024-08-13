#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> seg, nums;

int build(int node, int l, int r) {
    if (l == r) return seg[node] = nums[l];
    int mid = (r+l)/2;
    return seg[node] = build(node*2, l, mid) ^ build(node*2+1, mid+1, r);
}

int query(int node, int l, int r, int a, int b) {
    if (l > b || r < a) return 0;
    if (l >= a && r <= b) return seg[node];
    int mid = (l+r)/2;
    return query(node*2, l, mid, a, b) ^ query(node*2+1, mid+1, r, a, b);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;
    nums.resize(n); seg.resize(n*4);

    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    build(1, 0, n-1);

    for (int i=0; i<k; i++) {
        int a, b; cin >> a >> b; a--; b--;
        cout << query(1, 0, n-1, a, b) << "\n";
    }


    return 0;
}
