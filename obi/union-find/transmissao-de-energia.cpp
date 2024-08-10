#include <bits/stdc++.h>

using namespace std;

vector<int> tower;
vector<int> sz;

int find(int a) {
    if (tower[a] == a) return a;
    return tower[a] = find(tower[a]);
}

void uno(int p, int q, int& n) {
    int a = find(p), b = find(q);
    if (a == b) return;
    if (a < b) swap(a, b);
    tower[b] = a;
    sz[a] += sz[b];
    n--; 
}

int main() {

    int t = 1;


    while (true) {
        int n, v; cin >> n >> v;
        if (n == 0 && v == 0) break;
        tower.resize(n);
        sz.assign(n, 1);
        for (int i=0; i<n; i++) {
            tower[i] = i;
        }

        int ans = n-1;

        for (int i=0; i<v; i++) {
            int a, b; cin >> a >> b;
            a--; b--;
            uno(a, b, ans);
        }


        cout << "Teste " << t << "\n";
        if (ans == 0) cout << "normal\n";
        else cout << "falha\n";
        cout << "\n";

        t++;
        
        tower.clear();
        sz.clear();
        
    }
}
