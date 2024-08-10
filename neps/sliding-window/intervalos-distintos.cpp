#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> num(n);
    unordered_set<int> rep;

    for (int i=0; i<n; i++) {
        cin >> num[i];
    }

    int dif=0, best=0;

    for (int l=0, r=0; r < n && l < n;) {
        if (rep.find(num[r]) == rep.end()) {
            dif++;
            rep.insert(num[r]);
            best = max(dif, best);
            r++;
        }
        else {
            while (rep.find(num[r]) != rep.end() && l<r) {
                rep.erase(num[l]);
                l++;
                dif--;
            }
        }
    }

    cout << best << "\n";

    return 0;
}