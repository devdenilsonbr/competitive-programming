#include <bits/stdc++.h>


using namespace std;

const int maxn = 10010;
const int inf = 1e9;

int visited[maxn];
vector<int> family[maxn];
int prof[maxn];

void bfs(int a) {
    
    int p = 0;
    prof[a] = 0;
    queue<int> con;
    con.push(a);

    while (!con.empty()) {
        int curr = con.front();
        con.pop();

        for (auto ng:family[curr]) {
            if (!visited[ng]) {
                prof[ng] = prof[curr]+1;
                visited[ng] = 1;
                con.push(ng);
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
        family[i].push_back(parent);
        family[parent].push_back(i);
    }

    visited[0] = 1;

    bfs(0);

    vector<int> ge[maxn];

    int tam=-inf;

    for (int i=1; i<=r; i++) {
        ge[prof[i]].push_back(i);
        tam = max(tam, prof[i]);
    }

    int di[maxn]={0};

    for (int i=0; i<present; i++) {
        int num;
        cin >> num;
        di[prof[num]]++;
    }


    for (int i=1; i<=tam; i++) {
        double top = (double)di[i];
        double bot = (double)ge[i].size();
        cout << fixed << setprecision(2) << top/bot * 100 << " ";
    }
    cout << "\n";

    return 0;
}