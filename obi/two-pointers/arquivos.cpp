#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long N, S, res=0;
	cin >> N >> S;
	vector<long long> v(N);
	
	for (int i=0; i<N; i++) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());
	int l=N-1, r=0;
	
	while (r < l) {
		if (v[l]+v[r] <= S) {
			res++;
			l--; r++;
		}
		else {
			res++;
			l--;
		}
	}
	
	if (l == r) {
		res++;
	}
	
	cout << res << "\n";
	
	
	return 0;
}