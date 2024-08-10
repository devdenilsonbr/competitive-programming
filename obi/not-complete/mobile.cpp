#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

vector<int> graph[maxn];
bool vis[maxn];
int deep[maxn];
int times[maxn];

void bfs(int a) {
    vis[a] = 1;
    queue<int> next;
    next.push(a);
    while (!next.empty()) {
        int curr = next.front();
        next.pop();
        for (auto e:graph[curr]) {
            if (!vis[e]) {
                vis[e] = 1;
                deep[e] = deep[curr]+1;
                next.push(e);
            }
        }
    }
}

int main() {
    int n; cin >> n;

    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        times[a]++; times[b]++;
    }

    bfs(0);

    vector<int> fo;

    for (int i=1; i<=n; i++) {
        if (times[i] == 1) {
            fo.push_back(deep[i]);
        }
    }

    int base = fo[0];
    bool ans = 1;

    for (auto e:fo) {
        if (e != base) {
            ans = 0; break;
        }
    }

    if (ans) cout << "bem\n";
    else cout << "mal\n";


    return 0;
}
