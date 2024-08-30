#include <bits/stdc++.h>

using namespace std;

vector<char> seg, nums;

char To_Form(int a) {
    if (a == 0) return '0';
    else if (a < 0) return '-';
    else return '+';
}

char compare(char a, char b) {
    if (a == '0' || b == '0') return '0';
    if (a == '-' && b == '-') return '+';
    if (a == '-' || b == '-') return '-';
    if (a == '+' && b == '+') return '+';
}

int build(int node, int l, int r) {
    if (r == l) {
        return seg[node] = nums[l];
    }
    int mid = (r+l)/2;
    return seg[node] = compare(build(node*2, l, mid), build(node*2+1, mid+1, r));
}

void update(int node, int l, int r, int a, char v) {
    if (l == r) {
        seg[node] = nums[a] = v;
        return;
    }
    int mid = (l+r)/2;
    if (a >= l && a <= mid) update(node*2, l, mid, a, v);
    else update(node*2+1, mid+1, r, a, v);
    seg[node] = compare(seg[node*2], seg[node*2+1]);
}

char query(int node, int l, int r, int a, int b) {
    if (l > b || r < a) return '+';
    if (l >= a && r <= b) return seg[node];
    int mid = (l+r)/2;
    return compare(query(node*2, l, mid, a, b), query(node*2+1, mid+1, r, a, b));
}


int main() {
    int n, k;
    
    while (cin >> n >> k) {
        seg.resize(n*4);
        nums.resize(n);

        for (int i=0; i<n; i++) {
            int v; cin >> v;
            nums[i] = To_Form(v);
        }

        build(1, 0, n-1);

        while (k--) {
            char op; cin >> op;
            if (op == 'C') {
                int pos, value; cin >> pos >> value;
                pos--;
                update(1, 0, n-1, pos, To_Form(value));
            }
            else {
                int a, b; cin >> a >> b;
                a--; b--;
                cout << query(1, 0, n-1, a, b);
            }
        }

        cout << "\n";

    }



    return 0;
}
