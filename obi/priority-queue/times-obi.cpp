#include <bits/stdc++.h>

using namespace std;


int main() {
	vector<string> t[1010]; 
	priority_queue<pair<int, string>> jog;
	int n, q; cin >> n >> q;
	
	for (int i=0; i<n; i++) {
		string name;
		int power;
		cin >> name >> power;
		jog.push({power, name});
	}	
	
	int j=0;
	while (!jog.empty()) {
		t[j].push_back(jog.top().second);
		j = (j+1)%q;
		jog.pop();
	}
	
	for (int i=0; i<q; i++) {
		cout << "Time " << i+1 << "\n";
		sort(t[i].begin(), t[i].end());
		for (auto e:t[i]) {
			cout << e << "\n";
		}
		cout << "\n";
	}
	
	
	return 0;
}