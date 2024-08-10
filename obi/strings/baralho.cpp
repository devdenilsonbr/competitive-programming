#include <bits/stdc++.h>

using namespace std;

int main() {
	
	char n1, n2, tipo;
	
	int co=13, es=13, ou=13, pa=13;
	string wc="as", we="as", wo="as", wp="as";
	
	unordered_map<string, char> copas;
	unordered_map<string, char> espadas;
	unordered_map<string, char> ouros;
	unordered_map<string, char> paus;
	
	while (cin >> n1 >> n2 >> tipo) {
		string ch = string(1, n1) + string(1, n2);
		if (tipo == 'C' && wc != "erro") {
			if (copas.find(ch) == copas.end()) {
				copas[ch] = tipo;
				co--;
			}
			else {
				wc = "erro";
			}
		}
		else if (tipo == 'E' && we != "erro") {
			if (espadas.find(ch) == espadas.end()) {
				espadas[ch] = tipo;
				es--;
			}
			else {
				we = "erro";
			}
		}
		else if (tipo == 'O' && wo != "erro") {
			if (ouros.find(ch) == ouros.end()) {
				ouros[ch] = tipo;
				ou--;
			}
			else {
				wo = "erro";
			}
		}
		else if (tipo == 'P' && wp != "erro") {
			if (paus.find(ch) == paus.end()) {
				paus[ch] = tipo;
				pa--;
			}
			else {
				wp = "erro";
			}
		}
	}
	
	cout << co << " " << es << " " << ou << " " << pa << "\n";
	
	return 0;
}