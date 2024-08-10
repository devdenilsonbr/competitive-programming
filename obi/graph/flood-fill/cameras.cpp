#include <bits/stdc++.h>

using namespace std;

const int maxn = 50;

char matriz[maxn][maxn];
int n, m;

vector<int> dx={0, 1, -1, 0};
vector<int> dy={1, 0, 0, -1};

bool vef(int a, int b) {
    return a >= 1 && a <= n && b >= 1 && b <= m && matriz[a][b] == '.';
}

void dfs(int a, int b) {
    for (int j=0; j<4; j++) {
        int na, nb;
        na = a + dx[j];
        nb = b + dy[j];
        if (vef(na, nb)) {
            matriz[na][nb] = 'V';
            dfs(na, nb);
        }
    }
}

int main() {
    cin >> m >> n;
    int k; cin >> k;
    char mteste[maxn][maxn];
    

    for (int a=1; a<=n; a++) {
        for (int b=1; b<=m; b++) {
            matriz[a][b] = '.';
            mteste[a][b] = '.';
        }
    }
    for (int i=0; i<k; i++) {
        int a, b; char c;
        cin >> a >> b >> c;
        mteste[b][a] = c;
        matriz[b][a] = c;
    }

    for (int a=1; a<=n; a++) {
        for (int b=1; b<=m; b++) {
            if (mteste[a][b] == 'N') {
                int in=a;
                while (in >= 1) {
                    matriz[in][b] = 'H';
                    in--;
                }
            }
            if (mteste[a][b] == 'S') {
                int in=a;
                while (in <= n) {
                    matriz[in][b] = 'H';
                    in++;
                }
            }
            if (mteste[a][b] == 'L') {
                int in=b;
                while (in <= m) {
                    matriz[a][in] = 'H';
                    in++;
                }
            }
            if (mteste[a][b] == 'O') {
                int in=b;
                while (in >= 1) {
                    matriz[a][in] = 'H';
                    in--;
                }
            }
        }
    }

    if (matriz[1][1] == 'H') {
        cout << "N\n";
        return 0;
    }

    dfs(1, 1);

    if (matriz[n][m] == 'V') {
        cout << "S\n";
    } else {
        cout << "N\n";
    }


    return 0;
}