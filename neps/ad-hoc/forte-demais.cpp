#include <bits/stdc++.h>

using namespace std;

int main() {
	int qu, st, cont=0;
	long long sumleft=0, sumright=0;
	list<int> left;
	list<int> right;
	
	cin >> qu >> st;
	
	for(int i=0; i<qu; i++) {
		int value; cin >> value;
		left.push_back(value);
		sumleft += value;
	}
	for(int i=0; i<st; i++) {
		int value; cin >> value;
		right.push_back(value);
		sumright += value;
	}
	
	while (sumleft != sumright) {
		if (sumleft > sumright) {
			sumleft -= left.front();
			left.pop_front();
		}
		else {
			sumright -= right.back();
			right.pop_back();
		}
		cont++;
	}
	
	cout << cont << "\n";
	
	return 0;
}