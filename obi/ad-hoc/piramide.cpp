#include <bits/stdc++.h>

using namespace std;

int main() {
	int number[6];
	int sum=0, sum_five=0, it_sum, two_sum;
	char answer = 'N';
	
	for (int i=0; i<6; i++) {
		cin >> number[i];
		if (number[i] > sum) {
			sum = number[i];
			it_sum = i;
		}
		sum_five += number[i];
	}
	
	sum_five = sum_five - sum;
	
	for (int a=0; a<6; a++) {
		if (a != it_sum) {
			for (int b=0; b<6; b++) {
				if (b != it_sum) {
					two_sum = number[a] + number[b];
					if (two_sum == sum && sum_five-two_sum == sum) {
						answer = 'S';
						break;
					}
				}
			}
		}
	}
	
	cout << answer << "\n";
	
	return 0;
}