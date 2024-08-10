#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> stayed;

int main() {
    int n; cin >> n;

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        stayed.push_back({b, a});
    }

    sort(stayed.begin(), stayed.end());

    int cont = 1, best = 1;

    for (int i=0; i<n-1; i++) {
        int curr = stayed[i].first;
        
        while (curr >= stayed[i+1].second) cont++;
        best = max(cont, best);
    }

    cout << best << "\n";

    return 0;
}