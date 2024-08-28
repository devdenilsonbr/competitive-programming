#include <bits/stdc++.h>
#define int long long
#define lim 200007

using namespace std;

const int MAXN = 19;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;
    int hier[MAXN][n+1];

    hier[0][1] = 0;

    for (int i=2; i<=n; i++) {
        cin >> hier[0][i];
    }

    for (int i=1; i<MAXN; i++) {
        for (int k=1; k<=n; k++) {
            if (hier[i-1][k] == 0) {
                hier[i][k] = 0;//como o ancestral de 1 é uma excessao, para evitar loops ou acessos invalidos é feito uma vef
                continue;
            }

            hier[i][k] = hier[i-1][hier[i-1][k]];
        }
    }
        
    while(q--) {
        int emp, back; cin >> emp >> back;
        for (int i=0; i<MAXN; i++) {
            if ((1 << i) > back) continue;
            if (back & (1 << i)) emp = hier[i][emp];//ligado(logica do bitmask)
            if (emp == 0) break;
        }
        if (emp == 0) cout << "-1\n";
        else cout << emp << "\n";
    }

    return 0;
}
