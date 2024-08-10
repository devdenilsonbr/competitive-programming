#include <bits/stdc++.h>


using namespace std;

int main() {
	int N, iter=0;
	cin >> N;
	string name;
	vector<string> names_rooms;
	vector<string> names_younger;
	map<int, string> dormindo;
	
	for (auto it=0; it<N; it++) {
		cin >> name;
		names_rooms.push_back(name);
	}
	for (auto it=0; it<N; it++) {
		cin >> name;
		names_younger.push_back(name);
	}
	
	for (auto it=0; it<N-1; it++) {
		cout << names_younger[iter] << " ";
		if (names_rooms[it] == names_younger[iter]) {
			iter++;
			auto sleep = dormindo.find(iter);
			if (sleep != dormindo.end()) {
				if (sleep->second == names_younger[iter]) {
					iter++;
				}
			}
		}
		dormindo[it] = names_rooms[it];
	}
	cout << names_younger[iter] << "\n";  
    return 0;
}