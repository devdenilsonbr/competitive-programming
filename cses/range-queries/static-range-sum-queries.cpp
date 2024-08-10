#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, Q;
	cin >> N >> Q;
	long long int vetor[N+10];
	
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
			cout << vetor[fi]-vetor[in-1] << "\n";
		}
		else {
			cout << vetor[fi] << "\n";
		}
	}
	
	return 0;
}