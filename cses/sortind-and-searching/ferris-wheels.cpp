#include <bits/stdc++.h>

#define int long long

using namespace std;

int solve(vector<int> child, int limit) {
    int t = (int)child.size()-1;
    int count=0;
    for (int r=0, l=t; r<=l;) {
        if (child[r]+child[l] <= limit) {
            count++;
            r++; l--;
        }
        else if (child[r]+child[l] > limit) {
            if (child[l] <= limit) {
                count++;
                l--;
            }
            else if (child[l] > limit) {
                l--;
            }
        }
    }
    return count;
}

int32_t main () {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, lim;
    cin >> n >> lim;
    vector<int> ch(n);

    for (int i=0; i<n; i++) {
        cin >> ch[i];
    }

    sort(ch.begin(), ch.end());

    cout << solve(ch, lim) << "\n";

    return 0;
}