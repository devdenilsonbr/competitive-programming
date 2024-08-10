#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

int m[maxn][maxn];
int l, c;

bool vef(int a, int b) {
    return a >= 0 && a < l && b >= 0 && b<c && m[a][b] != 0;
}

vector<int> dx = {0, 1, -1, 0};
vector<int> dy = {1, 0, 0, -1};

void dfs(int a, int b) {
    for (int k=0; k<4; k++) {
        int new_a, new_b;
        new_a = a + dx[k];
        new_b = b + dy[k];
        if (vef(new_a, new_b)) {
            m[new_a][new_b] = 0;
            dfs(new_a, new_b);
        }
    }
}

int main() {
    cin >> l >> c;

    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            cin >> m[i][j];
        }
    }
    int cont=0;

    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            if (m[i][j] == 1) {
            	m[i][j] = 0;
                dfs(i, j);
                cont++;
            }
        }
    }
    
    cout << cont << "\n";


    return 0;
}