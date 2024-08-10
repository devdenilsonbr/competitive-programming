#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

const int maxn = 1010;

char m[maxn][maxn];
bool path[maxn][maxn];
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int h, w;

bool vef(int a, int b) {
    return a >= 0 && b >= 0 && a < h && b < w && m[a][b] == '.';
}

bool bfs(int a, int b) {
    queue<pii> indo;
    indo.push({a, b});
    bool control = 0;


    while (!indo.empty()) {
        int x = indo.front().first;
        int y = indo.front().second;
        indo.pop();
        
        for (int k=0; k<4; k++) {
            int nx, ny;
            nx = x + dx[k];
            ny = y + dy[k];
            if (vef(nx, ny) && m[nx][ny] == 'B')  {
                control = 1;
            }
            if (vef(nx, ny)) {
                m[nx][ny] = '#';
                indo.push({nx, ny});
                if (!control) {
                    path[nx][ny] = 1;
                }
            }
        }
    }
    return control;
}

int main() {
    cin >> h >> w;
    int ini_l, ini_c;

    for (int a=0; a<h; a++) {
        for (int b=0; b<w; b++) {
            cin >> m[a][b];
            if (m[a][b] == 'A') {
                ini_l = a; ini_c = b;
            }
        }
    }

    bool there = bfs(ini_l, ini_c);

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cout << path[i][j];
        }
        cout << "\n";
    }



    return 0;
}