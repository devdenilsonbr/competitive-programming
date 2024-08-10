#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, sum, value;
	cin >> N >> sum;
	vector<long long> shooting(N);
	char answer = 'N';
	
	for (int i=0; i<N; i++) {
		cin >> shooting[i];
	}
	
	int sum_prefix=0, iter=0;
	
	for (int it=0; it < N; it++) {
		sum_prefix += shooting[it];
		
		while (sum_prefix > sum && iter<it) {
			sum_prefix -= shooting[iter];
			iter++;
		}
		
		if (sum_prefix == sum) {
			answer = 'S';
		}
		
	}
	
	cout << answer << "\n";	
	
	
	return 0;
}