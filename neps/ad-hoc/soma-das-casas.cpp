#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, value, house_one, house_two, sum;
    set<int> number_search;
    vector<int> number;
    cin >> N;
    for (auto it=0; it<N; it++) {
        cin >> value;
        number.push_back(value);
        number_search.insert(value);
    }
    cin >> sum;
    int aux;
    auto search = number_search.end();
    for (auto it=0; it<N; it++) {
        aux = sum - number[it];
        search = number_search.find(aux);
        if (search != number_search.end()) {
            house_one = number[it];
            house_two = *search;
        }
    }
    
    cout << house_two << " " << house_one << "\n";

    return 0;
}