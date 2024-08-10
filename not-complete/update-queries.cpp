#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> ans;
    vector<int> position;

    for (int i=0; i<n; i++) {
        string start, change;
        
        int size_string, update;
        cin >> size_string >> update >> start;
        for (int a=0; a<update; a++) {
            int p; cin >> p;
            position.push_back(p);
        }
        cin >> change;

        for (auto& e:position) {
            int z = e-1;
            int x = e-1;
            while (change[z] == '0') {
                z++;
            }
            start[x] = change[z];
            change[z] = '0';
        }

        ans.push_back(start);
        position.clear();
    }

    for (auto& e:ans) {
        cout << e << "\n";
    }

    return 0;
}