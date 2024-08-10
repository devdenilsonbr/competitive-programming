#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	char res='S';
	cin >> N;
	vector<int> v(N);
	
	for (int i=0; i<N; i++) {
		cin >> v[i];
	}
	
	int r=0, l=N-1;
	int soma=v[r]+v[l];
	while (r <= l) {
		r++; l--;
		if (v[r]+v[l] != soma) {
			res = 'N';
			break;
		}
	}
	
	cout << res << "\n";
	
	return 0;
}