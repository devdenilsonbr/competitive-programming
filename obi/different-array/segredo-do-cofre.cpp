#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int n, q;
int vet[maxn], f[maxn];
long long alg[10];

void da(int l, int r, int d) {
	f[l] += d;
	f[r+1] -= d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> q;

	for (int i=1; i<=n; i++) {
		cin >> vet[i];
	}

	int last=1;

	da(1, 1, 1);

	for (int i=0; i<q; i++) {
		int next;
		cin >> next;

		int l = min(last, next), r = max(last, next);

		da(l, r, 1);
		da(last, last, -1);

		last = next;
		
	}

	for (int i=1; i<=n; i++) {
		f[i] += f[i-1];
		alg[vet[i]] += f[i];
	}

	for (int i=0; i<10; i++) {
		cout << alg[i] << " ";
	}
	
	cout << "\n";

	return 0;
}
