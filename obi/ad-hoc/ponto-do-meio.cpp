#include <bits/stdc++.h>

using namespace std;

int main() {
	long long start=2, rep;
	long long res;
	cin >> rep;
	long long cl;
	
	for (int i=0; i<rep; i++) {
		cl = start + start-1;
		res = cl*cl;
		start = cl;
	}
	
	cout << res << "\n";
	
	
	return 0;
}