#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> visited;
int heranca[100000];

void bfs (int x) {
	queue<int> vef;
	vef.push(x);
	visited[x] = true;
	heranca[0] = 0;
	
	while(!vef.empty()) {
		x = vef.front();
		vef.pop();
		
		for (auto& vz:g[x]) {
			if (!visited[vz]) {
				visited[vz] = true;
				vef.push(vz);
				heranca[vz] = x;	
			}
		}
	}
}

stack<int> path(int a, int b) {
	stack<int> caminho;
	caminho.push(b);
	int atual = b;
	while (atual != a) {
		caminho.push(heranca[atual]);
		atual = heranca[atual];
	}
	
	return caminho;
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int v, e;
	cin >> v >> e;
	g.resize(v);
	visited.assign(v, false);
	
	for (int i=0; i<e; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	bfs(0);
	
	if (!visited[v-1]) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	
	stack<int> caminho_f = path(0, v-1);
	
	cout << caminho_f.size() << "\n";
	
	vector<int> res;
	
	while (!caminho_f.empty()) {
		cout << caminho_f.top()+1 << " ";
		caminho_f.pop();
	}
	
	cout << "\n";
	return 0;
}