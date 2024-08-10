#include <bits/stdc++.h>

using namespace std;

const int maxn = 260;
const int inf = 1e9;

int salas[maxn][maxn];
int s, c;

void floyd() {

    for (int k=1; k<=s; k++) {
        for (int i=1; i<=s; i++) {
            for (int j=1; j<=s; j++) {
                salas[i][j] = min(salas[i][j], salas[i][k]+salas[j][k]);
            }
        }
    }

}

int main() {
    cin >> s >> c;

    for (int i=1; i<=s; i++) {
        for (int j=1; j<=s; j++) {
            if (i == j) {
                salas[i][j] = 0;
                continue;
            }
            salas[i][j] = inf;
        }
    }

    for (int i=0; i<c; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (salas[a][b] < c) continue;
        salas[a][b] = c;
        salas[b][a] = c;
    }

    floyd();

    int small = inf;

    for (int i=1; i<=s; i++) {
        int bigger = -inf;
        for (int j=1; j<=s; j++) {
            bigger = max(bigger, salas[i][j]);
        }
        small = min(bigger, small);
    }

    cout << small << "\n";


    return 0;
}