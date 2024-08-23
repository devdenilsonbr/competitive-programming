#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> planets(n);

    for (int i=0; i<n; i++) {
        planets[i] = i;
        int v; cin >> v;
        planets[i] = v-1;
    }

    

    for (int i=0; i<k; i++) {
        int p, tep, ans; cin >> p >> tep;
        if (tep == 0) {
            cout << p << "\n";
            continue;
        }
        p--;
        ans = planets[p];
        while(--tep) {
            ans = planets[ans];
        }
        cout << ans+1 << "\n";
    }

    
    
    return 0;
}
