#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;

int visited[maxn]={0};
int prof[maxn];
vector<int> bus[maxn];

void bfs(int a) {
    queue<int> line;
    line.push(a);
    prof[a] = 0;

    while (!line.empty()) {
        int curr = line.front();
        line.pop();

        for (auto e:bus[curr]) {
            if (!visited[e]) {
                prof[e] = prof[curr]+1;
                visited[e] = 1;
                line.push(e);
            }
        }
    }

}

int main() {
    int n, in, fi;
    cin >> n >> in >> fi;

    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        bus[a].push_back(b);
        bus[b].push_back(a);
    }

    bfs(in);

    cout << prof[fi] << "\n";
    

    return 0;
}
