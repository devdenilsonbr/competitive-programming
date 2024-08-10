#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, L, C;
	string text;
	char delimiter = ' ';
	
	while (cin >> N >> L >> C >> text) {
		vector<string> words;
		string word;
		stringstream ss(text);
		
		while (getline(ss, word, delimiter)) {
			words.push_back(word);
		}
		
		for (const auto& p : words) {
			cout << p << " ";
		}
		cout << "\n";
	}
	
	return 0;
}