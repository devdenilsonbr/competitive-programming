#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	set<int> alunos;
	
	for (int i=0; i<N; i++) {
		int valor;
		cin >> valor;
		alunos.insert(valor);
	}
	
	cout << (int)alunos.size() << "\n";
	
	
	return 0;
} 