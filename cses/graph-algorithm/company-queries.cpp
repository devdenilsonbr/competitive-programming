#include <bits/stdc++.h>

using namespace std;

const int MAXN = 32;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;
    int hier[MAXN][n+1];

    hier[0][1] = -1;

    for (int i=2; i<=n; i++) {
        cin >> hier[0][i];
    }

    for (int i=1; i<MAXN; i++) {
        for (int k=1; k<=n; k++) {
            if (hier[i-1][k] == -1) {
                hier[i][k] = -1;//como o ancestral de 1 é uma excessao, para evitar loops ou acessos invalidos é feito uma vef
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
        }
        cout << emp << "\n";
    }

    return 0;
}
