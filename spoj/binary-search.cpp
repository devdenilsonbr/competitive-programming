#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, Q, value, find_number;
	cin >> N >> Q;
	vector<int> number;
	vector<int> number_find;
	
	for (auto i=0; i<N; i++) {
		cin >> value;
		number.push_back(value);
	}
	
	for (auto i=0; i<Q; i++) {
		cin >> find_number;
		auto it = lower_bound(number.begin(), number.end(), find_number);
		if (*it == find_number) {
			number_find.push_back(it - number.begin());
		}
		else {
			number_find.push_back(-1);
		}
	}
	
	for (int element:number_find) {
		cout << element << "\n";
	}
	
    
}