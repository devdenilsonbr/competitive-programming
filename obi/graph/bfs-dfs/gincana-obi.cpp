#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;;
vector<int> visited;

void dfs(int x) {
	visited[x] = 1;
	for (int v:graph[x]) {
		if (visited[v] == -1) {
			visited[v] = 1;
			dfs(v);
		}
	}
}

int main() {
	int V, A; cin >> V >> A;
	graph.resize(V);
	visited.assign(V, -1);
	
	for (int i=1; i<=A; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	int cont=0;
	
	for (int i=0; i<V; i++) {
		if (visited[i] == -1) {
			cont++;
			dfs(i);
		}
	}
	
	cout << cont << "\n";
	
	
	return 0;
}