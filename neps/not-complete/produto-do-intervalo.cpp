#include <bits/stdc++.h>

using namespace std;

vector<int> seg, nums;

int build(int node, int l, int r) {
    if (l == r) return seg[node] = nums[l];
    int mid = (l+r)/2;
    return seg[node] = build(node*2, l, mid) * build(node*2+1, mid+1, r);
}

void update(int node, int l, int r, int x, int v) {
    if (l == r) {
        seg[node] = nums[x] = v;
        return;
    }
    int mid = (l+r)/2;
    if (x >= l && x <= mid) update(node*2, l, mid, x, v);
    else if (x > mid && x <= r) update(node*2+1, mid+1, r, x, v);
    seg[node] = seg[node*2] * seg[node*2+1];
}

int querry(int node, int l, int r, int a, int b) {
    if (l > b || r < a) return 1;
    if (l >= a && r <= b) return seg[node];
    int mid = (l+r)/2;
    return querry(node*2, l, mid, a, b) * querry(node*2+1, mid+1, r, a, b);
}

int32_t main() {
    int n, k;
    
    while (cin >> n >> k) {
        seg.resize(n*4);
        nums.resize(n);

        for (int i=0; i<n; i++) {
            cin >> nums[i];
        }

        build(1, 0, n-1);

        for (int i=0; i<k; i++) {
            char a; cin >> a;
            if (a == 'C') {
                int pos, v; cin >> pos >> v;
                pos--;
                update(1, 0, n-1, pos, v);
            }
            else {
                int in, fi; cin >> in >> fi;
                in--; fi--;
                int ans = (querry(1, 0, n-1, in, fi));
                if (ans > 0) cout << "+";
                else if (ans < 0) cout << "-";
                else if (ans == 0) cout << "0";
            }
        }
        cout << "\n";
    }



    return 0;
}
