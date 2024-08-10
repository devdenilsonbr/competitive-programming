#include <bits/stdc++.h>

using namespace std;

int main () {
    int n; cin >> n;
    vector<string> ans;

    for (int i=0; i<n; i++) {
        long long a, b, small, big;
        cin >> a >> b;
        small = min(a, b);
        big = max(a, b);
        if (big - small > 3) {
            ans.push_back("NO");
            continue;
        }
        if ((big+small)%3 == 0) {
            ans.push_back("YES");
        }
        else {
            ans.push_back("NO");
        }
    }

    for (auto e:ans) {
        cout << e << "\n";
    }


}