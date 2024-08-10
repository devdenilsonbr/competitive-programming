#include <bits/stdc++.h>

using namespace std;

const int maxn = 500;
char matriz[maxn][maxn];
int m, n;

bool vef(int x, int y) {
	return x >= 0 && x < m && y>= 0 && y<n && matriz[x][y] == 'o';
}

void dfs(int a, int b) {
	if (vef(a, b) && a+1<m) {
		if (matriz[a+1][b] == '.') {
			matriz[a+1][b] = 'o';
			dfs(a+1, b);
		}
		if (matriz[a][b+1] == '.' && matriz[a+1][b] == '#' && b+1 < n) {
			matriz[a][b+1] = 'o';
			dfs(a, b+1);
		}
		if (matriz[a][b-1] == '.' && matriz[a+1][b] == '#' && b-1>=0) {
			matriz[a][b-1] = 'o';
			dfs(a, b-1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n;
	int in_c;
	
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			cin >> matriz[i][j];
			if (matriz[0][j] == 'o') {
				in_c=j;
			};
		}
	}
	
	dfs(0, in_c);
	
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			cout << matriz[i][j];
		}
		cout << "\n";
	}
	
	
	return 0;
}