#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6;

int sz[maxn];
int business[maxn];

int find(int p) {
    if (business[p] == p) return p;
    return business[p] = find(business[p]);//tem que chamar o lider, quando desempilhar tudo fica o mesmo
}

void uno(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);//unir o lider que tem mais vertices
    business[b] = a;
    sz[a] += sz[b]; //somar tds os vertices do outro conjunto
}

int main() {
    int n, k; cin >> n >> k;
    for (int i=1; i<=n; i++) {
        sz[i] = 1;
        business[i] = i;
    }

    vector<char> ans;

    for (int i=0; i<k; i++) {
        char a; int b, c;
        cin >> a >> b >> c;
        if (a == 'F') uno(b, c);
        else if (find(b) == find(c)) cout << "S\n";
        else cout << "N\n";
    }


    return 0;
}