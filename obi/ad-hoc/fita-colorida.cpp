#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> num(n);
	vector<int> zero;
	vector<int> direita(n);
	vector<int> esquerda(n);
	vector<int> final(n);

	for (int i=0; i<n; i++) {
		cin >> num[i];
		if (num[i] == 0) zero.push_back(i);
	}
	int sum=1;
	for (int i=0; i<n; i++) {
		if (num[i] != 0) {
			esquerda[i] += sum;
			sum++;
		}
		else {
			sum = 1;
		}
	}
	sum = 1;
	for (int i=n-1; i>=0; i--) {
		if (num[i] != 0) {
			direita[i] += sum;
			sum++;
		}
		else {
			sum = 1;
		}
	}
	int in = zero[0], fi=zero.size()-1;
	
	for (int i=0; i<in; i++) {
		final[i] = direita[i];
		if (final[i] > 9) {
			final[i] = 9;
		}
	}
	for (int i=in; i<zero[fi]; i++) {
		final[i] = min(direita[i], esquerda[i]);
		if (final[i] > 9) {
			final[i] = 9;
		}
	}
	for (int i=zero[fi]; i<n; i++) {
		final[i] = esquerda[i];
		if (final[i] > 9) {
			final[i] = 9;
		}
	}
	

	for (int i=0; i<n; i++) {
		cout << final[i] << " ";
	}
	
	
	return 0;
}
 