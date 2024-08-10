#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b) {
	while (b != 0) {
		int aux = b;
		b = a%b;
		a = aux;
	}
	if (a<0) {
		return a * -1;
	}
	return a;
}

int main() {
	int N, n1, d1, n2, d2, aux1, aux2; 
	vector<pair<int, int>> n_and_d;
	cin >> N;
	char slash, operation;
	for (int it=0; it<N; it++) {
		cin >> n1 >> slash >> d1 >> operation >> n2 >> slash >> d2;
		switch (operation) {
			case '+':
				aux1 = (n1*d2) + (n2*d1);
				aux2 = d1*d2;
				n_and_d.push_back(make_pair(aux1, aux2));
				break;
			case '-':
				aux1 = (n1*d2) - (n2*d1);
				aux2 = d1*d2;
				n_and_d.push_back(make_pair(aux1, aux2));
				break;
			case '*':
				aux1 = n1*n2;
				aux2 = d1*d2;
				n_and_d.push_back(make_pair(aux1, aux2));
				break;
			case '/':
				aux1 = n1*d2;
				aux2 = d1*n2;
				n_and_d.push_back(make_pair(aux1, aux2));
				break;
		}
	}
	int multiple;
	for (auto element:n_and_d) {
		cout << element.first << "/" << element.second << " = ";
		multiple = mdc(element.first, element.second);
		cout << element.first/multiple << "/" << element.second/multiple << "\n";
	}
	
	return 0;
}