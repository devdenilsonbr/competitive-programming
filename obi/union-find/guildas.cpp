#include <bits/stdc++.h>

using namespace std;

vector<int> guild;
vector<int> points;

int find(int a) {
    if (guild[a] == a) return a;
    return guild[a] = find(guild[a]);
}

void uno(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;
    if (points[a] < points[b]) swap(a, b);
    guild[b] = a;
    points[a] += points[b];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    while (true) {
        int n, k; cin >> n >> k;
        if (n == 0 && k == 0) break;
        guild.resize(n);
        points.resize(n);
        for (int i=0; i<n; i++) {
            guild[i] = i;
            cin >> points[i];
        }
        int cont=0;
        for (int i=0; i<k; i++) {
            int q, a, b; cin >> q >> a >> b;
            a--; b--;
            if (q == 1) uno(a, b);
            else {
                int v = find(a), p = find(b);
                if (points[v] > points[p] && guild[0] == v) cont++;
                else if (points[p] > points[v] && guild[0] == p) cont++;
            }
        }

        cout << cont << "\n";
        guild.clear();
        points.clear();

    }



    return 0;
}
