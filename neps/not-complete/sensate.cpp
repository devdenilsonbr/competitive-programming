#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> sensate;
unordered_map<string, int> qi;
unordered_map<string, int> qi_club;
unordered_map<string, int> sz;
unordered_map<string, int> used;

string findd(string a) {
    if (sensate[a] == a) return a;
    return sensate[a] = findd(sensate[a]);
}

void uno(string p, string q) {
    string a = findd(p), b = findd(q);
    if (sz[a] < sz[b]) swap(a, b);
    sensate[b] = a;
    sz[a] += sz[b];
    if (qi_club[a] > 5 || qi_club[b] > 5) {
        qi_club[a] = qi_club[b] = 2;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k, q; cin >> n >> k >> q;

    for (int i=0; i<n; i++) {
        string name; int level;
        cin >> name >> level;
        sensate[name] = name;
        qi[name] = level;
        qi_club[name] = 1;
        sz[name] = 1;
    }

    for (int i=0; i<k; i++) {
        string fusion, with;
        cin >> fusion >> with;
        uno(fusion, with);
        used[fusion] = used[with] = 1;
    }

    for (int i=0; i<q; i++) {
        string e; cin >> e;
        if (used.find(e) == used.end()) cout << "S\n";
        else if (qi[e] >= 5 && qi_club[e] == 1) cout << "S\n";
        else cout << "N\n"; 
    }


    return 0;
}
