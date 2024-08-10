#include <bits/stdc++.h> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, cont=0;
	unordered_map<int, int> tacos;
	
	cin >> n;
	
	for (int i=0; i<n; i++) {
		int a;
		cin >> a;
		if (tacos.find(a) == tacos.end()) {
			tacos[a] = 1;
			cont+=2;
		}
		else {
			tacos.erase(a);
		}
	}
	
	cout << cont << "\n";
	
	return 0;
}