#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, r;
	bool res=false;
	int m[maxn][maxn]={0};
	cin >> n >> r;
	
	for (int i=0; i<r; i++) {
		int a, b;
		cin >> a >> b;
		m[a][b] = 1;
		m[b][a] = 1;
	}
	
	for (int i=1; i<=n; i++) {
		bool conec = true;
		for (int j=1; j<=n; j++) {
			if (i!=j && m[i][j] == 0) {
				conec=false;
			}
		}
		if (conec) {
			res = true;
			break;
		}
	}
	
	if (res) {
		cout << "S\n";
	}
	else {
		cout << "N\n";
	}
	
	
	return 0;
}