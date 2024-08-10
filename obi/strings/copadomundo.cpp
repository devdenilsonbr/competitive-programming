#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	
	vector<char> jogadores[5];
	
	for (char i='A'; i<='P'; i++) {
		jogadores[0].push_back(i);
	}
	for (int i=0; i<16; i+=2) {
		cin >> a >> b;
		if (a > b) {
			jogadores[1].push_back(jogadores[0][i]);
		}
		else {
			jogadores[1].push_back(jogadores[0][i+1]);
		}
	}
	for (int i=0; i<8; i+=2) {
		cin >> a >> b;
		if (a > b) {
			jogadores[2].push_back(jogadores[1][i]);
		}
		else {
			jogadores[2].push_back(jogadores[1][i+1]);
		}
	}
	for (int i=0; i<4; i+=2) {
		cin >> a >> b;
		if (a > b) {
			jogadores[3].push_back(jogadores[2][i]);
		}
		else {
			jogadores[3].push_back(jogadores[2][i+1]);
		}
	}
	
	cin >> a >> b;
	if (a > b) {
		jogadores[4].push_back(jogadores[3][0]);
	}
	else {
		jogadores[4].push_back(jogadores[3][1]);
	}

	cout << jogadores[4][0] << "\n";
	
	
	
	return 0;
}