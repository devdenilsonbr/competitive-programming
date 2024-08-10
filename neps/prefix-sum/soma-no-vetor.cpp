#include <iostream>

using namespace std;

const int maxs = 500000;

void vetor_somado(int vetor[maxs], int tamanho) {
	for (auto i=1; i<tamanho; i++) {
		vetor[i] = vetor[i-1] + vetor[i];
	}
}

int main() {
	int N, K;
	cin >> N;
	int vetor[maxs];
	for (auto it=0; it<N; it++) {
		cin >> vetor[it];
	}
	
	vetor_somado(vetor, N);
	
	for (auto it=0; it<N; it++) {
		
		cout << vetor[it] << " ";
	}
	
	
	return 0;
}