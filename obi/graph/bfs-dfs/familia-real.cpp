#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

const int maxn = 10010;
const int inf = 1e9;

int visited[maxn];
vector<pii> family[maxn];
int dist[maxn];

void dijkstra(int a) {
    
    priority_queue<pii, vector<pii>, greater<pii>> con;
    con.push({0, a});

    while (!con.empty()) {
        int curr = con.top().second;
        con.pop();
        if (visited[curr]) continue;
        visited[curr] = 1;
        for (auto ng:family[curr]) {
            int nv = ng.first, cost = ng.second;
            if (dist[nv] > dist[curr]+cost) {
                dist[nv] = dist[curr]+cost;
                con.push({dist[nv], nv});
            }
        }
    }
}

int main() {
    int r, present;
    cin >> r >> present;

    for (int i=1; i<=r; i++) {
        int parent;
        cin >> parent;
        family[i].push_back({parent, 1});
        family[parent].push_back({i, 1});
    }

    for (int i=1; i<=r; i++) {
        dist[i] = inf;
    }

    dijkstra(0);

    vector<int> ge[maxn];

    int tam=-inf;

    for (int i=1; i<=r; i++) {
        ge[dist[i]].push_back(i);
        tam = max(tam, dist[i]);
    }

    int di[maxn]={0};

    for (int i=0; i<present; i++) {
        int num;
        cin >> num;
        di[dist[num]]++;
    }


    for (int i=1; i<=tam; i++) {
        double top = (double)di[i];
        double bot = (double)ge[i].size();
        cout << fixed << setprecision(2) << top/bot * 100 << " ";
    }
    cout << "\n";

    return 0;
}
