#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

const int maxn = 1e6+10;
int dsu[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, d;
    vector<pii> duo_same;
    vector<pii> duo_not_same;

    cin >> n >> m >> d;

    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        duo_same.push_back({a, b});
    }    
    for (int i=0; i<d; i++) {
        int a, b; cin >> a >> b;
        duo_not_same.push_back({a, b});
    }

    for (int i=0; i<n/3; i++) {
        int a, b, c; cin >> a >> b >> c;
        dsu[a] = a; dsu[b] = a; dsu[c] = a;
    } 

    int cont=0;

    for (auto e:duo_same) {
        if (dsu[e.first] != dsu[e.second]) cont++;
    }   
    for (auto e:duo_not_same) {
        if (dsu[e.first] == dsu[e.second]) cont++;
    }

    cout << cont << "\n";

    return 0;
}
