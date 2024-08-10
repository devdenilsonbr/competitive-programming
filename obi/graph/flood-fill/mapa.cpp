#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;

char m[maxn][maxn];
int L, C, res_l, res_c;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

bool vef(int x, int y) {
	return x >= 0 && x < L && y >= 0 && y < C;
}

void dfs(int a, int b) {
	res_l = a; res_c = b;
	if (vef(a, b)) {
		for (int k=0; k<4; k++) {
			int novo_a = a + dx[k];
			int novo_b = b + dy[k];
			if (m[novo_a][novo_b] == 'H') {
				m[novo_a][novo_b] = 'o';
				dfs(novo_a, novo_b);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> L >> C;
	int in_l, in_c;
	
	for (int i=0; i<L; i++) {
		for (int j=0; j<C; j++) {
			cin >> m[i][j];
			if (m[i][j]=='o') {
				in_l = i;
				in_c = j;
			}
		}
	}
	
	dfs(in_l, in_c);
	
	cout << res_l+1 << " " << res_c+1 << "\n";
	
	return 0;
}