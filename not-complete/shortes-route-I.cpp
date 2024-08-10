#include <bits/stdc++.h>

#define int long long

#define pii pair<int, int>

using namespace std;

const int maxn = 100010;
const int inf = 1e18+10;

int dist[maxn];
bool vis[maxn];
vector<pii> graph[maxn];
int n, m;


void dijkstra(int a) {

    for (int i=1; i<=n; i++) {
        dist[i] = inf;
    }

    dist[a] = 0; 

    priority_queue<pii, vector<pii>, greater<pii>> streets;

    streets.push({0, a});

    while (!streets.empty()) {
        int node = streets.top().second;
        streets.pop();
        if (vis[node]) continue;
        vis[node] = 1;

        for (auto e:graph[node]) {
            int ng = e.first, cost = e.second;
            if (dist[ng] > dist[node] + cost) {
                dist[ng] = dist[node] + cost;
                streets.push({dist[ng], ng});
            }
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dijkstra(1);

    for (int i=1; i<=n; i++) {
        cout << dist[i] << " ";
    }

    cout << "\n";

    return 0;
}