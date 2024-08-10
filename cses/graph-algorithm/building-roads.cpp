#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int visited[maxn]={0};
vector<int> city[maxn];

void bfs(int a) {
    queue<int> roads;
    roads.push(a);

    while (!roads.empty()) {
        int curr = roads.front();
        roads.pop();
        for (auto ng:city[curr]) {
            if (!visited[ng]) {
                visited[ng] = 1;
                roads.push(ng);
            }
        }
    }
}

int main() {
    int n, e; cin >> n >> e;

    for (int i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        city[a].push_back(b);
        city[b].push_back(a);
    }

    int count=0;

    vector<int> connect;
    //vector<pair<int, int>> new_roads;

    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            connect.push_back(i);
            visited[i] = 1;
            bfs(i);
            count++;
        }
    }

    if (count-1 == 0) {
        cout << "0\n";
        return 0;
    }


    cout << count-1 << "\n";

    for (int i=0; i<count-1; i++) {
        cout << connect[i] << " " << connect[i+1] << "\n";
    }

    return 0;
}