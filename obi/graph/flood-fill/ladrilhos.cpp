#include <bits/stdc++.h>

using namespace std;

const int maxn = 250;

int n, m;
int tile[maxn][maxn];
vector<int> dx={0, 1, -1, 0};
vector<int> dy={1, 0, 0, -1};

bool vef(int a, int b) {
    return a >= 0 && a<n && b >= 0 && b<m && tile[a][b] != -1;
}

void dfs(int a, int b, int& c, int d) {
    for (int p=0; p<4; p++) {
        int new_a, new_b;
        new_a = a + dx[p];
        new_b = b + dy[p];
        if (vef(new_a, new_b) && tile[new_a][new_b] == d) {
            tile[new_a][new_b] = -1;
            c++;
            dfs(new_a, new_b, c, d);
        }
    }
}


int main() {
    cin >> n >> m;

    for (int a=0; a<n; a++) {
        for (int b=0; b<m; b++) {
            cin >> tile[a][b];
        }
    }

    int best= INT_MAX;

    for (int a=0; a<n; a++) {
        for (int b=0; b<m; b++) {
            if (tile[a][b] != -1) {
                int count = 1;
                int current = tile[a][b];
                tile[a][b] = -1;
                dfs(a, b, count, current);
                best = min(best, count);
            }
        }
    }
    
    cout << best << "\n";

    return 0;
}