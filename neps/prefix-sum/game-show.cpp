#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    long long sum=0, best=0;

    for (int i=0; i<n; i++) {
        int a; cin >> a;
        sum += a;
        best = max(sum, best);
    }

    cout << 100 + best << "\n";

    return 0;
}