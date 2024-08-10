#include <bits/stdc++.h>

using namespace std;

vector <int> dx = {0, 1, 0, -1};
vector <int> dy = {1, 0, -1, 0};

const int maxn = 1010;

char m[maxn][maxn];
int l, c;

bool vef(int x, int y) {
	return x >= 0 && x < l && y >= 0 && y < c;
}

void dfs(int a, int b) {
	if (vef(a, b)) {
		m[a][b] = '#';
		for (int k=0; k<4; k++) {
			int n_a = a + dx[k];
			int n_b = b + dy[k];
			if (m[n_a][n_b] == '.') {
				m[n_a][n_b] = '#';
				dfs(n_a, n_b);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> l >> c;
	
	for (int i=0; i<l; i++) {
		for (int j=0; j<c; j++) {
			cin >> m[i][j];
		}
	}
	
	int cont=0;
	
	for (int i=0; i<l; i++) {
		for (int j=0; j<c; j++) {
			if (m[i][j] == '.') {
				dfs(i, j);
				cont++;
			}
		}
	}
	
	cout << cont << "\n";
	
	return 0;
}