#include <bits/stdc++.h>

#define ppi pair<int, pair<int, int>>

using namespace std;

const int inf = 1e9;
const int maxn = 1010;
int m[maxn][maxn];
int dist[maxn][maxn];
int n;

vector<int> dx={0, 1, 0, -1};
vector<int> dy={1, 0, -1, 0};

bool vef(int a, int b) {
    return a>=0 && a<n && b>=0 && b<n;
}

void dijkstra (int a, int b) {
    priority_queue<ppi, vector<ppi>, greater<ppi>> work;
    dist[a][b] = 0;
    work.push({0, {a, b}});

    while (!work.empty()) {
        int x = work.top().second.first;
        int y = work.top().second.second;
        int curr = work.top().first;
        work.pop();


        if (curr == dist[x][y]) {
            for (int k=0; k<4; k++) {
            int new_a, new_b;
            new_a = x + dx[k];
            new_b = y + dy[k];
            if (vef(new_a, new_b)) { 
                if (dist[new_a][new_b] > dist[x][y]+m[new_a][new_b]) {
                    dist[new_a][new_b] = dist[x][y]+m[new_a][new_b];
                    work.push({dist[new_a][new_b], {new_a, new_b}});
                }
            }
            }
        }
        




    }
}


int main() {
    cin >> n;

    for (int a=0; a<n; a++) {
        for (int b=0; b<n; b++) {
            cin >> m[a][b];
            dist[a][b] = inf;
        }
    }

    dijkstra(0, 0);

    cout << dist[n-1][n-1] << "\n";


    return 0;
}