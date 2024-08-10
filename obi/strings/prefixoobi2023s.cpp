#include <iostream>

using namespace std;

int main() {
	int N, M, cont=0;
	string palavra, prefixo;
	cin >> N >> palavra >> M >> prefixo;
	if (palavra[0] == prefixo[0]) {
		for (auto i=0; i<M; i++) {
			if (prefixo[i] == palavra[i]) {
				cont++;
			}
			else {
				break;
			}
		}
		cout << cont << "\n";
	}
	else {
		cout << "0" << "\n";
	}
	
	return 0;
}