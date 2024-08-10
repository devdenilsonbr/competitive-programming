#include <bits/stdc++.h>

using namespace std;

int multiple(int a) {
	if (a % 3 > 0) {
		return 0;
	}
	return 1;
}

int main() {
	int N;
	vector<int> algarism;
	cin >> N;
	if (multiple(N)) {
		while (N > 0) {
			algarism.push_back(N%10);
			N = N/10;
		}
		sort(algarism.begin(), algarism.end());
		for (auto i=algarism.size()-1; i!=-1; i--) {
			cout << algarism[i];
		}
		cout << "\n";
	}
	else {
		cout << "-1\n";
	}
	
}