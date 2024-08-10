#include <iostream>
#include <algorithm>

using namespace std;

bool ison(int n, int j) { // bit j - posicao, n - numero utilizado
    if (n & (1 << j)) return 1; // mover o bit 1 j vezes para a esquerda
    return 0; // operador & compara bits
}

void turnon(int& n, int j) {
    n = n | (1 << j); // o operador | compara bits
}

int bitmasks[15];

int main() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;

    for (int i=0; i<n; i++) {
        cin >> bitmasks[i];
    }

    int ans=0;

    for (int mask = 0; mask < (1 << n); mask++) {// 
        long long sum;
        int big=99999999, small=-2;

        for (int i=0; i<n; i++) {
            if (ison(n, i)) {
                sum += bitmasks[i];
                big = max(bitmasks[i], big);
                small = min(bitmasks[i], small);
            }
            if (sum >= l && sum <= r && (big-small) >= x) ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}