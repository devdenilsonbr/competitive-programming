#include <bits/stdc++.h>

using namespace std;

vector<int> repetidos(const vector<int>& numeros) {
	unordered_map<int, int> quant;
	vector<int> repetidos;
	
	for (int e:numeros) {
		quant[e]++;
	}
	
	for (const auto& e:quant) {
		if (e.second >= 1) {
			repetidos.push_back(e.first);
		}
	}
	
	return repetidos;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, cont=0, maior=0;
	cin >> N;
	vector<int> vet(N);
	vector<int> rep;
	
	for (int i=0; i<N; i++) {
		cin >> vet[i];
	}
	
	rep = repetidos(vet);
	
	if ((int)rep.size() == 1 || (int)rep.size() == 0) {
		cout << "1\n";
		return 0;
	}
	
	for (int i=0; i<(int)rep.size(); i++) {
		for (int j=0; j<(int)rep.size(); j++) {
			if (i != j) {
				int atual = rep[i];
				int vez = 1;
				for (int k=0; k<N; k++) {
					if (vet[k] == atual && vez == 1) {
						cont++;
						vez = 0;
						atual = rep[j];
					}
					else if (vet[k] == atual && vez == 0) {
						cont++;
						vez = 1;
						atual = rep[i];
					}
				}
				maior = max(cont, maior);
				cont = 0;
			}
		}
	}


	cout << maior << "\n";
	
	return 0;
}