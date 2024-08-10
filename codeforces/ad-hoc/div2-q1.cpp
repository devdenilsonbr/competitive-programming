#include <iostream>

const int maxn = 100;

using namespace std;

int par(int A) {
	if (A%2==0) {
		return 1;
	}
	return 0;
}

int main() {
	int N, move, cube;
	cin >> N;
	string anwser[maxn+10];
	for (auto it=0; it<N; it++) {
		cin >> move >> cube;
		if (move < cube) {
			anwser[it] = "No";
		}
		else if(move == cube) {
			anwser[it] = "Yes";
		}
		else {
			if (par(move) && !par(cube) || !par(move) && par(cube)) {
				anwser[it] = "No";
			}
			else {
				anwser[it] = "Yes";
			}
		}
	}
	for (auto it=0; it<N; it++) {
		cout << anwser[it] << "\n";
	}
	
	
	return 0;
}