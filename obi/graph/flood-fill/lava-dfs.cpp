#include <bits/stdc++.h>

using namespace std;

const int maxn = 505;

char m[maxn][maxn];
int n;
char forca;

vector<int> dx={0, -1, 1, 0};
vector<int> dy={1, 0, 0, -1};

bool vef(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y<n && (int)m[x][y]-'0' <= (int)forca-'0' && m[x][y] != '*';
}

void dfs(int a, int b) {
	m[a][b] = '*';
	for (int k=0; k < 4; k++) {
		int novo_a, novo_b;
		novo_a = a + dx[k];
		novo_b = b + dy[k];
		if (vef(novo_a, novo_b)) {
			dfs(novo_a, novo_b);
		}
	}
}

int main() {
	cin >> n >> forca;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> m[i][j];
		}
	}
	
	if ((int)m[0][0]-'0' <= (int)forca-'0') {
		m[0][0] = '*';
		dfs(0, 0);
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << m[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}