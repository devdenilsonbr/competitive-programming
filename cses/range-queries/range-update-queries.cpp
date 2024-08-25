#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> nums;

void update(int l, int r, int a, int b, int v) {
    if (l > b || r < a) return;
    if (l == r && l == a || l == b) {
        nums[l] = nums[r] += v;
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, a, b, v);
    update(mid+1, r, a, b, v);
}


int32_t main() {
    int n, k; cin >> n >> k;
    nums.resize(n);

    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    for (int i=0; i<k; i++) {
        int q; cin >> q;
        if (q == 2) {
            int k; cin >> k;
            k--;
            cout << nums[k] << "\n";
        }
        else {
            int a, b, c; cin >> a >> b >> c;
            a--; b--;
            update(0, n-1, a, b, c);
        }
    }

    

    return 0;
}
