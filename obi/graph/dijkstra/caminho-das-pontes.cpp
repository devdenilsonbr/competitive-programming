#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

const int inf = 1e9;
const int maxn = 10e2+5;
int n, e, dist[maxn];

bool visited[maxn];

vector<pii> graph[maxn];

void dijkstra(int R) {

    for (int i=0; i<=n; i++) {
        dist[i] = inf;
    }

    dist[R] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> distof;

    distof.push({0, R});

    while (!distof.empty()) {
        int curr = distof.top().second;
        distof.pop();

        if (visited[curr]) {
            continue;
        }
        visited[curr] = true;

        for (auto neigh:graph[curr]) {
            int ng = neigh.first, d = neigh.second;

            if (dist[ng] > dist[curr]+d) {

                dist[ng] = dist[curr] + d;
                distof.push({dist[ng], ng});

            }

        }
    }

}

int main() {
    cin >> n >> e;
    n += 2;

    for (int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijkstra(0);

    cout << dist[n-1] << "\n";


    return 0;
}