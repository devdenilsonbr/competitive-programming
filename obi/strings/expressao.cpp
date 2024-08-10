#include <bits/stdc++.h>

using namespace std;

char valida(string a) {
	stack<char> s;
	for (int i=0; i<(int)a.size(); i++) {
		if (a[i] == '{' || a[i] == '(' || a[i] == '[') {
			s.push(a[i]);
		}
		else {
			if (s.empty()) {
				return 'N';
			}
			if (a[i] == ')' && s.top() == '(') {
				s.pop();
			}
			else if (a[i] == '}' && s.top() == '{') {
				s.pop();
			}
			else if (a[i] == ']' && s.top() == '[') {
				s.pop();
			}
			else {
				return 'N';
			}
		}
	}
	return s.empty() ? 'S' : 'N';
	
	
}


int main() {
	int N; cin >> N;
	string ex;
	char vet[N];
	
	for (int i=0; i<N; i++) {
		cin >> ex;
		vet[i] = valida(ex);
	}
	
	for (const auto& e:vet) {
		cout << e << "\n";
	}
	
	
	
	return 0;
}