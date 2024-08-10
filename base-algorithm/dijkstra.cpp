#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

const int maxn = 1e6;
const int inf = 1e9;

int n, m, k;
vector<pii> graph[maxn];
int dist[maxn];
bool vis[maxn];

void dijktra(int a) {
    int cont=0;
    for (int i=1; i<=n; i++) {
        dist[i] = inf;
    }
    dist[a] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> boat;
    boat.push({0, a});

    while (!boat.empty()) {
        int curr = boat.top().second;
        boat.pop();

        if (vis[curr]) continue;
        vis[curr] = 1;

        for (auto e:graph[curr]) {
            int ng = e.first, cost = e.second;
            if (dist[ng] > dist[curr]+cost) {
                cont++;
                dist[ng] = dist[curr]+cost;
                boat.push({dist[ng], ng});
            }
        }
    
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijktra(1);


    for (int i=1; i<=n; i++) {
        cout << dist[i] << " ";
    }


    return 0;
}