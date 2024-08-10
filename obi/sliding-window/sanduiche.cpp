#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, D;
	cin >> N >> D;
	vector<int> v(N*2);
	
	for (int i=0; i<N; i++) {
		cin >> v[i];
		v[N+i] = v[i];
	}
	
	long long soma=v[0];
	int res=0;
	
	for (int r=0, l=0; l<N;) {
		if (r-l >= N) {
			soma-=v[l];
			l++;
		}
		else if(soma<D) {
			r++;
			soma += v[r];
		}
		else if(soma > D) {
			soma -= v[l];
			l++;
		}
		else if(soma == D) {
			res++;
			r++;
			soma += v[r];
			soma -= v[l];
			l++;
		}
	}
	
	cout << res << "\n";
	
	
	return 0;
}