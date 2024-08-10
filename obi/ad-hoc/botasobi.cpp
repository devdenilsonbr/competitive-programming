#include <bits/stdc++.h>

using namespace std;

struct calcado {
	int tam;
	char lado;
};

bool compare (calcado a, calcado b) {
	return a.tam < b.tam;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	vector<calcado> botas(N);
	
	for (int i=0; i<N; i++) {
		cin >> botas[i].tam >> botas[i].lado;
	}
	
	sort(botas.begin(), botas.end(), compare);
	
	int cont=0, atual=botas[0].tam, lado_d=0, lado_e=0;
	
	for (int i=0; i<N; i++) {
		
	}
	
	cout << cont << "\n";
	
	return 0;
}