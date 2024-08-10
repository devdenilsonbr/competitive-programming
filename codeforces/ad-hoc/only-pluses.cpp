#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ans;

    for (int i=0; i<n; i++) {
        int a, b, c;
        vector<int> num;
        cin >> a >> b >> c;
        num.push_back(a); num.push_back(b); num.push_back(c);
        sort(num.begin(), num.end());

        for (int j=0; j<5; j++) {
            if (num[0] <= num[1] && num[0] <= num[2]) num[0]++;
            else if (num[1] <= num[0] && num[1] <= num[2]) num[1]++;
            else if (num[2] <= num[0] && num[2] <= num[1]) num[2]++;
            
        }
        ans.push_back(num[0]*num[1]*num[2]);
        
    }

    for (auto e:ans) {
        cout << e << "\n";
    }

    return 0;
}