#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, sum=0; cin >> n;
    vector<int> setone;
    vector<int> settwo;

    for (int i=1; i<=n; i++) {
        sum += i;
    }

    if (sum%2>0) {
        cout << "NO\n";
        return 0;
    }

    int setsum = sum/2;
    int setsumone=0;

    for (int i=n; i>0; i--) {
        if (setsumone < setsum && setsumone+i <= setsum) {
            setone.push_back(i);
            setsumone += i;
        }
        else {
            settwo.push_back(i);
        }
    }

    cout << "YES\n";
    cout << setone.size() << "\n";
    for (auto e:setone) {
        cout << e << " ";
    }
    cout << "\n";
    cout << settwo.size() << "\n";
    for (auto e:settwo) {
        cout << e << " ";
    }
    cout << "\n";

}