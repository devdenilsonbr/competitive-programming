#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b;
	string num;
	
	while (cin >> a >> b) {
		if (a == 0 && b == 0) break;
		
		cin >> num;
		string maior;
		int apagado = b;
		
		for (char c : num) {
			while (!maior.empty() && maior.back() < c && apagado > 0) {
				maior.pop_back();
				apagado--;
			}
			
			maior.push_back(c);
			
		}
		
		while (apagado > 0) {
			maior.pop_back();
			apagado--;
		}
		
		cout << maior << "\n";
		
	}
	
	return 0;
}