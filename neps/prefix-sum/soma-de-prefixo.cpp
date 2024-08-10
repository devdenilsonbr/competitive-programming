#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	long long int vetor[N+10];
	vector<long long int> somas;
	
	for (int i=1;i<=N;i++) {
		cin >> vetor[i];
		if (i==1) {
			vetor[0] = vetor[i];
		}
	}
	
	long long int soma=vetor[1];
	
	for (int i=2;i<=N;i++) {
		vetor[i] = soma + vetor[i];
		soma = vetor[i];
	}
	
	int in, fi;
	for (int i=0; i<Q;i++) {
		cin >> in >> fi;
		if (in != 1) {
			somas.push_back(vetor[fi]-vetor[in-1]);
		}
		else {
			somas.push_back(vetor[fi]);
		}
	}
	
	for (int element:somas) {
		cout << element << "\n";
	}
	
	return 0;
}