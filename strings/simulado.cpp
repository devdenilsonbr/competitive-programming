#include <bits/stdc++.h>

using namespace std;

int main() {
	string m1, m2, res1="", res2="", res3="";
	cin >> m1 >> m2;
	
	for (int i=0; i<(int)m1.size(); i++) {
		if (m1[i] != '#') {
			res1 += string(1, m1[i]);
		}
	}
	for (int i=0; i<(int)m2.size(); i++) {
		if (m2[i] != '#') {
			res2 += string(1, m2[i]);
		}
	}
	
	int tam = max((int)res1.size(), (int)res2.size());
	
	
	for (int i=0; i<tam; i++) {
		if (i < (int)res1.size()) {
			res3 += string(1, res1[i]);
		}
		if (i <(int) res2.size()) {
			res3 += string(1, res2[i]);
		}
	}
	
	cout << res3 << "\n";
	
	return 0;

}