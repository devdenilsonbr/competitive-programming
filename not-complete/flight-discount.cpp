#include <bits/stdc++.h>

#define pii pair<int, int>
#define int long long

using namespace std;

const int maxn = 1e5+10;
const int inf = 1e10;

int visited[maxn]={0};
int dist[maxn];
vector<pii> travel[maxn];
int parent[maxn];

void dijkstra(int a) {

    dist[a] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> price;
    price.push({0, a});

    while (!price.empty()) {
        int curr = price.top().second;
        price.pop();
        

        for (auto e:travel[curr]) {
            int node = e.first, cost = e.second;
            if (dist[node] > dist[curr]+cost) {
                dist[node] = dist[curr]+cost;
                price.push({dist[node], node});
                parent[node] = curr;
            }
        }
    }



}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int r, c;
    cin >> r >> c;

    for (int i=1; i<=r; i++) {
        dist[i] = inf;
    }

    for (int i=0; i<c; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        travel[a].push_back({b, c});
    }
    
    dijkstra(1);

    vector<int> discount;

    int in=r, fi=1;

    while (in != fi) {
        int curr = in;
        for (auto e:travel[parent[in]]) {
            int next = e.first;
            if (next == in) {
                discount.push_back(e.second);
            }
        }
        in = parent[in];
    }
    
    sort(discount.rbegin(), discount.rend());

    int coupon = discount[0];

    cout << (dist[r]-coupon) + (coupon/2) << "\n";

    return 0;
}