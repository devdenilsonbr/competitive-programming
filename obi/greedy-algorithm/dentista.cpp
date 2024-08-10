#include <bits/stdc++.h>

using namespace std;

struct horario {
	int ini, fim;
};

bool comparar(horario a, horario b) {
	return a.fim < b.fim;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, cont=1;
	cin >> N;
	vector<horario> consultas(N);
	
	for (int i=0; i<N; i++) {
		cin >> consultas[i].ini >> consultas[i].fim;
	}
	sort(consultas.begin(), consultas.end(), comparar);
	
	int fim=consultas[0].fim;
	
	for (int i=1; i<N; i++) {
		if (consultas[i].ini>= fim) {
			cont++;
			fim = consultas[i].fim;
		}
	}
	
	cout << cont << "\n";
	
	return 0;
}