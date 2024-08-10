#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ans;
    vector<int> ord(3);

    for (int i=0; i<n; i++) {
        int a, b, c;
        cin >> ord[0] >> ord[1] >> ord[2];
        sort(ord.begin(), ord.end());

        ans.push_back(abs(ord[0]-ord[1])+abs(ord[1]-ord[1])+abs(ord[1]-ord[2]));
    }

    for (auto& e:ans) {
        cout << e << "\n";
    }

    return 0;
}