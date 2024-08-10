#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vector<string> ans;

    for (int i=0; i<n; i++) {
        long long one_i, two_i, one_f, two_f;
        cin >> one_i >> two_i;
        cin >> one_f >> two_f;
        
        if (one_i > two_i) {
            if (one_f > two_f) {
                ans.push_back("YES");
            }
            else {
                ans.push_back("NO");
            }
        }
        else if (one_i < two_i) {
            if (one_f < two_f) {
                ans.push_back("YES");
            }
            else {
                ans.push_back("NO");
            }
        } 

    }

    for (auto e:ans) {
        cout << e << "\n";
    }

    return 0;
}