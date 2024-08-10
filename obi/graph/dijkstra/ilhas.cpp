#include <bits/stdc++.h>

#define pii pair<int, int>
#define pb push_back

using namespace std;

const int maxn = 1010;
const int inf = 1000000;

int dist[maxn];
vector<pii> graph[maxn];
bool visited[maxn];
int n, e;

void dijkstraS(int M) {
    
    
    for (int i=1; i<=n; i++) {
        dist[i] = inf;
    }

    dist[M] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> small;

    small.push({0, M});

    while (!small.empty()) {
        int curr = small.top().second;
        small.pop();

        if (visited[curr]) continue;

        visited[curr] = 1;


        for (auto np:graph[curr]) {
            int ng = np.first, d = np.second;
            if (dist[ng] > dist[curr]+d) {
                dist[ng] = dist[curr] + d;
                small.push({dist[ng], ng});
            }
        }

    }


}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> e;

    for (int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }

    int reference; cin >> reference;

    dijkstraS(reference);

    int bigger=0, smallest = inf;

    for (int i=1; i<=n; i++) {
        if (i == reference) continue;
        bigger = max(bigger, dist[i]);
        smallest = min(smallest, dist[i]);
    }

    cout << bigger - smallest << "\n";


    return 0;
}