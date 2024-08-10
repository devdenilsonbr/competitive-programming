#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> friends;
vector<bool> visited;

void bfs(int x) {
	visited[x] = true;
	queue<int> vis;
	vis.push(x);
	
	while (!vis.empty()) {
		x = vis.front();
		vis.pop();
		
		for (int e:friends[x]) {
			if (!visited[e]) {
				visited[e] = true;
				vis.push(e);
			}
		}
	}
}

int main() {
	int nodes, edges;
	cin >> nodes >> edges;
	friends.resize(nodes);
	visited.assign(nodes, false);
	
	for (int i=0; i<edges; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	
	int cont=0;
	
	for (int i=0; i<nodes; i++) {
		if (!visited[i]) {
			bfs(i);
			cont++;
		}
	}
	
	cout << cont << "\n";
	
	
	return 0;
}