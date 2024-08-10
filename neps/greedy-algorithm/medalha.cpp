#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, v, cont=0, maior_a=0, maior_v=0;
	set<int> med_a;
	set<int> med_v;
	cin >> a >> v;
	
	for (int i=0; i<a; i++) {
		int valor; cin >> valor;
		med_a.insert(valor);
		maior_a = max(valor, maior_a);
	}
	for (int i=0; i<v; i++) {
		int valor; cin >> valor;
		med_v.insert(valor);
		maior_v = max(valor, maior_v);
	}
	
	if (maior_a > maior_v) {
		med_a.erase(maior_a);
		while (!med_a.empty()) {
			int segundo_maior = *med_a.rbegin();
			if (segundo_maior < maior_v) break;
			med_a.erase(segundo_maior);
			cont++;
		}
	}
	else {
		med_v.erase(maior_v);
		while (!med_v.empty()) {
			int segundo_maior = *med_v.rbegin();
			if (segundo_maior < maior_a) break;
			med_v.erase(segundo_maior);
			cont++;
		}
	}
	
	cout << cont << "\n";
	
	return 0;
}