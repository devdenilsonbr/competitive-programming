#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, C;
	cin >> N >> C;
	map<long long, long long> instaled;
	map<long long, long long> available;
	vector<long long> search(N);
	
	for (int i=0; i<N; i++) {
		long long a, b; cin >> a >> b;
		instaled[a] = b;
		search[i] = a;
	}
	
	for(int i=0; i<C; i++) {
		long long a, b; cin >> a >> b;
		if (available.find(a) != available.end()) {
			if (instaled[a] < b) {
				available[a] = b;
			}
		}
		else {
			available[a] = b;
		}
		
	}
	
	for (int i=0; i<N; i++) {
		if (available.find(search[i]) != available.end()) {
			if (instaled[search[i]] > available[search[i]]) {
				available.erase(search[i]);
			}
		}
	}
	
	for (auto it=available.begin(); it!=available.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}
	
	
	return 0;
}