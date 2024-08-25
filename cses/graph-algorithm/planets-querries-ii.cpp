#include <bits/stdc++.h>
#define MAXN 32

using namespace std;

int main() {
    int n, q; cin >> n >> q;
    int travel[MAXN][n+1];

    for (int i=1; i<=n; i++) {
        cin >> travel[0][i];
    }

    for (int i=1; i<MAXN; i++) {
        for (int k=1; k<=n; k++) {
            travel[i][k] = travel[i-1][travel[i-1][k]];
        }
    }

    while (q--) {
        int a, b, cont=0; cin >> a >> b;
        bool ans = 0;
        for (int i=0, k=1; i<MAXN; i++, k++) {
            if ((1 << i) & k) {
                cont = k;
                a = travel[i][a];
                if (travel[i][a] == b) {
                    ans = 1; break;
                }
            } 
        }
        if (ans) cout << cont << "\n";
        else cout << "-1\n";
    }



    return 0;
}