#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6;

vector<int> tree[maxn];
int visited[maxn]={0};
int prof[maxn]={0};
int n;

int bfs(int a) {

    for (int i=1; i<=n; i++) {
        visited[i] = 0;
        prof[i] = 0;
    }

    int best=0;
    queue<int> fila;
    fila.push(a);

    while (!fila.empty()) {
        int curr = fila.front();
        fila.pop();

        for (auto e:tree[curr]) {
            if (!visited[e]) {
                visited[e] = 1;
                prof[e] = prof[curr]+1;
                best = max(best, prof[e]);
                fila.push(e);
            }
        }
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    int primeiro;

    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        primeiro = a;
    }

    if (n == 2) {
        cout << "1\n";
        return 0;
    }

    int num = bfs(primeiro);
    int segundo;

    for (int i=1; i<=n; i++) {
        if (prof[i] == num) {
            segundo = i;
            break;
        }
    }

    int bigger = bfs(segundo);

    cout << bigger << "\n";


    return 0;
}