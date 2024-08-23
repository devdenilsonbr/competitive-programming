#include <bits/stdc++.h>

using namespace std;

const int maxn = 500;

vector<int> graph[500];
vector<int> deep;
vector<int> heigth;

int bfs(int a, int n) {
    priority_queue<pair<int, int>> nums;
    nums.push({0, a});
    int ans = 0;
    while (!nums.empty()) {
        int curr = nums.top().second;
        nums.pop();

        for (auto e:graph[curr]) {
            if (heigth[curr] > heigth[e]) {
                deep[e] = max(deep[e], deep[curr]+1);
                nums.push({deep[e], e});
                ans = max(deep[e], ans);
            }
        }
        if (ans == n-1) return ans;
        
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, e, in; cin >> n >> e >> in;
    heigth.resize(n);
    deep.assign(n, 0);

    for (int i=0; i<n; i++) {
        cin >> heigth[i];
    }

    for (int i=0; i<e; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << bfs(in-1, n) << "\n";
    
    return 0;
}
