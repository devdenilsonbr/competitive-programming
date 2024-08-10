#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

const int inf = 1e9;
const int maxn = 150;

int dist[maxn];
bool visited[maxn]={0};
vector<pii> graph[maxn];

void dijkstra(int O) {
    dist[O] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> city;
    city.push({0, O});

    while (!city.empty()) {
        int curr = city.top().second;
        city.pop();

        if (visited[curr]) continue;
        visited[curr] = 1;

        for (auto side:graph[curr]) {
            int neigh = side.first, cost = side.second;
            if (dist[neigh] > dist[curr]+cost) {
                dist[neigh] = dist[curr]+cost;
                city.push({dist[neigh], neigh});
            }
        }


    }
}


int main() {
    int n, e; cin >> n >> e;

    for (int i=1; i<=n; i++) {
        dist[i] = inf;
    }

    for (int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijkstra(1);

    cout << dist[n] << "\n";

    return 0;
}