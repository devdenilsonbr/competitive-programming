#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long N, S;
	cin >> N >> S;
	vector<long long> v(N*2);
	
	for (int i=0; i<N; i++) {
		cin >> v[i];
		v[N+i] = v[i];
	}
	
	long long somap=0;
	long long res=0, r=0, l=0;
	
	while (r < N*2) {
		somap += v[r];
		r++;
		
		while (somap > S && l<r && l<N-1) {
			somap -= v[l];
			l++;
		}
		
		if (somap == S && r-l <= N) {
			res++;
		}
	}
	
	cout << res << "\n";
	
	
	return 0;
}