#include <bits/stdc++.h>

using namespace std;

const int maxn=1000;
int m, n, res;
char matriz[maxn][maxn];

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

bool vef(int a, int b) {
	return a >= 0 && a < m && b >= 0 && b < n && matriz[a][b] != '0';
}

void dfs(int a, int b, int cont) {
	if (matriz[a][b] == '2') {
		res = cont;
		return;
	}
	matriz[a][b] = '0';
	
	for (int k=0; k<4; k++) {
		int novo_a = a + dx[k];
		int novo_b = b + dy[k];
		
		if (vef(novo_a, novo_b)) {
			dfs(novo_a, novo_b, cont+1);
		}
	}
}

int main() {
	cin >> m >> n;
	int in_l, in_c;
	
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			cin >> matriz[i][j];
			if (matriz[i][j] == '3') {
				in_l = i;
				in_c = j;
			}
		}
	}
	
	dfs(in_l, in_c, 0);
	
	cout << res+1 << "\n";
	
	
	return 0;
}