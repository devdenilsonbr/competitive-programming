#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 1e6;

int nums[maxn];
int cont[maxn];

void df(int in, int fi) {
    cont[in] += 1;
    cont[fi+1] -= 1;

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;

    int bigger = -maxn;

    for (int i=1; i<=n; i++) {
        int a, b; cin >> a >> b;
        df(a, b);
        if (a > b) bigger = max(a, bigger);
        if (b > a) bigger = max(b, bigger);
    }

    int ans=-maxn;
    for (int i=1; i<=bigger; i++) {
        cont[i] = cont[i-1] + cont[i];
        ans = max(cont[i], ans);
    }

    for (int i=1; i<=bigger; i++) {
        cout << cont[i] << " ";
    }

    cout << ans << "\n";

    return 0;
}