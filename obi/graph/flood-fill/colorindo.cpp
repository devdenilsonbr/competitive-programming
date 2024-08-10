#include <bits/stdc++.h>

using namespace std;

const int maxn = 205;

int L, C, res=0;
int m[maxn][maxn]={0};
vector<int> dx={0, 1, -1, 0, 1, 1, -1, -1};
vector<int> dy={1, 0, 0, -1, 1, -1, -1, 1};

bool vef(int x, int y) {
	return x >= 0 && x < L && y >= 0 && y < C && m[x][y] == 0;
}

void dfs(int a, int b) {
	res++;
	
	for (int k=0; k<8; k++) {
		int novo_a = a + dx[k];
		int novo_b = b + dy[k];
		if (vef(novo_a, novo_b)) {
			m[novo_a][novo_b] = 1;
			dfs(novo_a, novo_b);
		}
	}
}


int main() {
	int in_l, in_c, vis;
	cin >> L >> C >> in_l >> in_c >> vis;
	
	
	for (int i=0; i<vis; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		m[a][b] = 1;
	}
	
	in_l--; in_c--;
	m[in_l][in_c] = 1;
	
	dfs(in_l, in_c);
	
	cout << res << "\n";
	
	return 0;
}