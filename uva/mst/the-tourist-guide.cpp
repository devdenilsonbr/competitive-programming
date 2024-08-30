#include <bits/stdc++.h>
#define tii tuple<int, int, int>
#define pii pair<int, int>
#define MAXN 200

using namespace std;

const int inf = 1e7;

vector<int> cities;
vector<int> sz, asc;
vector<bool> vis;

int find(int p) {
    if (cities[p] == p) return p;
    return cities[p] = find(cities[p]);
}

void uni(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    cities[b] = a;
    sz[a] += sz[b];
}

void bfs(int a, vector<int> graph[MAXN]) {
    vis[a] = 1;
    asc[a] = a;
    queue<int> travel;
    travel.push(a);
    while (!travel.empty()) {
        int curr = travel.front();
        travel.pop();

        for (auto e:graph[curr]) {
            if (!vis[e]) {
                vis[e] = 1;
                asc[e] = curr;
                travel.push(e);
            }
        }
    }
}

int main() {
    int n, m;
    int cont=1;

    while (cin >> n >> m) {
        if (!n && !m) break;
        cities.resize(n); sz.assign(n, 1); asc.resize(n);
        vis.assign(n, 0);
        vector<tii> roads;
        
        for (int i=0; i<n; i++) cities[i] = i;

        for (int i=0; i<m; i++) {
            int a, b, c; cin >> b >> c >> a;
            b--;c--;
            roads.push_back({a, b, c});
        }

        sort(roads.rbegin(), roads.rend());
        vector<int> graph[MAXN];
        int path[MAXN][MAXN];
        memset(path, inf, sizeof(path));

        for (auto [a, b, c]:roads) {
            if (find(b) != find(c)) {
                graph[b].push_back(c);
                graph[c].push_back(b);
                path[b][c] = a; path[c][b] = a;
                uni(b, c);
            }
        }

        bfs(0, graph);

        int ori, des, t; cin >> ori >> des >> t;
        ori--;des--;

        int ans=inf;

        while (asc[des] != ori) {
            int next = asc[des];
            ans = min(ans, path[des][next]);
            des = asc[des];
        }

        cout << ans << "\n";
        

    }



    return 0;
}
