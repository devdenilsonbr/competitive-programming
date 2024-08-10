#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, value, pair_of_shoes=0;
	char side;
	map<int, int> left_side;
	map<int, int> right_side;
	cin >> N;
	
	for (int i=0; i<N; i++) {
		cin >> value >> side;
		if (side == 'E') {
			left_side[value]++;
		}
		else if(side == 'D') {
			right_side[value]++;
		}
	}
	
	
	for (const auto& i:left_side) {
		int size = i.first;
		if (right_side.find(size) != right_side.end()) {
			
			pair_of_shoes += min(right_side[size], left_side[size]);
			
		}
	}
	
	
	cout << pair_of_shoes << "\n";
	
	
	return 0;
}