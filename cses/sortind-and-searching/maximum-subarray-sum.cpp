#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    long long sum=0, best=-9999999999;
    
    for (int i=0; i<n; i++) {
        long long v; cin >> v;
        sum = max(sum+v, v);
        best = max(sum, best);
    }

    cout << best << "\n";

    return 0;
}