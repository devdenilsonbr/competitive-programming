#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long n, cont=0;
	
	cin >> n;
	vector<long long> number(n);
	
	for (int i=0; i<n; i++) {
		cin >> number[i];
	}
	
	for (int i=0; i<n-1; i++) {
		if (number[i] > number[i+1]) {
			while (number[i+1] != number[i]) {
				number[i+1] += 1;
				cont++;
			}
		}
	}
	
	cout << cont << "\n";
	
	return 0;
}