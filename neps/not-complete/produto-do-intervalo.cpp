#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

vector<int> nums;
vector<int> tree;

int build(int node, int l, int r) {
    if (l == r) {
        tree[node] = nums[l];
        return tree[node];
    }
    int mid = (l+r)/2;
    return tree[node] = build(node*2, l, mid) * build(node*2+1, mid+1, r);
}

void update(int node, int l, int r, int pos, int v) {
    if (l == r) {
        tree[node] = v;
        nums[pos] = v;
        return;
    }

    int mid = (l+r)/2;
    if (pos >= l && pos <= mid) update(node*2, l, mid, pos, v);
    else update(node*2+1, mid+1, r, pos, v);

    tree[node] = tree[node*2] * tree[node*2+1];
}

int querry(int node, int cl, int cr, int l, int r) {
    if (cl > r || cr < l) return 1;
    if (cl >= l && cr <= r) return tree[node];
    int mid = (cr+cl)/2;
    return querry(node*2, cl, mid, l, r) * querry(node*2+1, mid+1, cr, l, r);
}

int main() {

    int n, k;

    while (cin >> n >> k) {
        nums.resize(n);
        tree.resize(n*4);
        for (int i=0; i<n; i++) {
            cin >> nums[i];
        }

        build(1, 0, n-1);

        for (int i=0; i<k; i++) {
            char c; int a, b;
            cin >> c >> a >> b;

            if (c == 'C') {
                a--;
                update(1, 0, n-1, a, b);
            }
            if (c == 'P') {
                a--; b--;
                int ans = querry(1, 0, n-1, a, b);
                if (ans > 0) cout << "+";
                else if (ans < 0) cout << "-";
                else cout << "0";
            }
        }
        cout << "\n";
        nums.clear();
        tree.clear();
    }
    return 0;
}
