#include <bits/stdc++.h>

using namespace std;

int main() {
	int sum=0, side_a, side_b;
	int number[6];
	char anwser = 'N';
	
	for (int i=0; i<6; i++) {
		cin >> number[i];
		sum += number[i];
	}
	
	for (int a=0; a<6; a++) {
		for (int b=0; b<6; b++) {
			for (int c=0; c<6; c++) {
				if (a != b && b != c && a != c) {
					side_a = number[a] + number[b] + number[c];
					side_b = sum - side_a;
					if (side_a == side_b) {
						anwser = 'S';
						break;
					}
				}
			}
		}
	}
	
	cout << anwser << "\n";
	
	return 0;
}