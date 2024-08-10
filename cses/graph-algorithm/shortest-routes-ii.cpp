#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 550;
const int inf = 1e18;

int dist[maxn][maxn];
int m[maxn][maxn];

int n;

void floyd_warshall() {

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (m[i][j] != inf) dist[i][j] = m[i][j];
            else dist[i][j] = inf;
        }
    }

    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[j][k]);
            }
        }
    }
}

int32_t main() {
    int routes, q;
    cin >> n >> routes >> q;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            m[i][j] = inf;
        }
    }

    for (int i=0; i<routes; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (m[a][b] <= c) continue;
        m[a][b] = c;
        m[b][a] = c;
    }

    floyd_warshall();

    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        if (dist[b][a] == inf) {
            cout << "-1\n";
        }
        else {
            cout << dist[b][a] << "\n";
        }
    }


    return 0;
}