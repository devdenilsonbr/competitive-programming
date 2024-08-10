#include <iostream>
#define int long long

using namespace std;

const int mod = 1e9+7;

int32_t main() {
    int n, ans=1;
    cin >> n;

    for (int i=0; i<n; i++) {
        ans *= 2;
        ans = ans % mod;
    }

    cout << ans << "\n";
}