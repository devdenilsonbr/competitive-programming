#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

const int maxn = 150;
const int inf = 1e9;

int dist[maxn];
vector<pii> graph[maxn];
int n, e;

void dijkstra (int O) {
    bool visited[maxn] = {0};

    for (int i=0; i<n; i++) {
        dist[i] = inf;
    }
    dist[O] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> travel;
    travel.push({0, O});

    while (!travel.empty()) {
        int curr = travel.top().second;
        travel.pop();

        if (visited[curr]) continue;

        visited[curr] = 1;

        for (auto side:graph[curr]) {
            int ng = side.first, cost = side.second;
            if (dist[ng] > dist[curr]+cost) {
                dist[ng] = dist[curr]+cost;
                travel.push({dist[ng], ng});
            }
        }



    }
}


int main() {
    cin >> n >> e;

    for (int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vector<int> ans;

    for (int i=0; i<n; i++) {
        int most = 0;
        dijkstra(i);
        for (int v=0; v<n; v++) {
            if (i == v) continue;
            most = max(most, dist[v]);
        }
        ans.push_back(most);
    }
    sort(ans.begin(), ans.end());

    cout << ans[0] << "\n";


    return 0;
}