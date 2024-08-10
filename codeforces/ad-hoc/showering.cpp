#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

int main() {
    int n; cin >> n;

    for (int i=0; i<n; i++) {
        int cases, shower, lim;
        int ans = 0;
        cin >> cases >> shower >> lim;
        vector<pii> darray;

        for (int j=0; j<cases; j++) {
            int l, r;
            cin >> l >> r;
            darray.push_back({l, r});
        }

        bool fin=0;

        if (darray[0].first >= shower) fin = 1;
        if (lim - darray[cases-1].second >= shower) fin = 1;
        if (fin) {
            cout << "YES\n";
            continue;
        }

        for (int j=0; j<cases-1; j++) {
            if ((abs(darray[j].second - darray[j+1].first)) >= shower) {
                fin = 1;
                break;
            }
        }

        if (fin) cout << "YES\n";
        else cout << "NO\n";
        darray.clear();        
    }


    return 0;
}
