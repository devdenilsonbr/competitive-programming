#include <bits/stdc++.h>

using namespace std;

int main() {
	int v, r, res;
	cin >> v >> r;
	
	for (int i=0; i<r; i++) {
		int a;
		cin >> a;
	}
	
	res = (v*v - v) - r*2;
	cout << res/2 << "\n"; 
	
	return 0;
}