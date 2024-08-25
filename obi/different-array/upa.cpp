#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int vetsum[maxn] = {0};

void different(int l, int r) {
    vetsum[l] += 1;
    vetsum[r] -= 1;
}

int main() {

    int n; cin >> n;


    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        different(a, b);
    }

    int ans = vetsum[0];

    for (int i=1; i<maxn; i++) {
        vetsum[i] = vetsum[i] + vetsum[i-1];
        ans = max(vetsum[i], ans);
    }


    cout << ans*20 << "\n";
    
    return 0;
}
