#include <bits/stdc++.h>

const int inf = 1e4;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;

    for (int i=0; i<n; i++) {
        int ans=0;
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        if (a1 > b1 && a2 > b2) ans++;
        if (a1 > b2 && a2 > b1) ans++;
        if (a2 > b1 && a1 > b2) ans++;
        if (a2 > b2 && a1 > b1) ans++;
        
        cout << ans << "\n";
        
    }

    return 0;
}
