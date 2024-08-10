#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	vector<int> num(n);
	vector<int> ans;
	
	if (n == 2 || n == 3) {
		cout << "NO SOLUTION\n";
		return 0;
	}
	
	for (int i=0; i<n; i++) {
		num[i] = i+1;
	}
	
	for (int i=1; i<n; i+=2) {
		ans.push_back(num[i]);
	}
	for (int i=0; i<n; i+=2) {
		ans.push_back(num[i]);
	}
	
	for (auto& e:ans) {
		cout << e << " ";
	}
	cout << "\n";
	
	return 0;
}