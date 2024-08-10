#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    vector<long long> res;

    for (int i=0; i<t; i++) {
        long long a, b, ans;
        cin >> a >> b;
        if (a > b) {
            if (a % 2 == 0) {
                ans = (a*a) - b+1;
            }
            else {
                ans = (a*a-((a*2) - 2)) + b-1;
            }
        }
        else if (b > a) {
            if (b % 2 > 0) {
                ans = (b*b) - a+1;
            }
            else {
                ans = (b*b-((b*2) - 2)) + a-1;
            }
        }
        else {
            ans = (a*a) - a+1;
        }
        res.push_back(ans);

    }

    for (auto e:res) {
        cout << e << "\n";
    }


    return 0;
}