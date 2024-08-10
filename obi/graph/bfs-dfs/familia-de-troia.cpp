#include <bits/stdc++.h>

using namespace std;

vector<int> visited;
vector<int> lista[50050];

void bfs(int x) {
	queue<int> pravisitar;
	visited[x] = 1;
	pravisitar.push(x);
	
	while (pravisitar.empty() == 0) {
		x = pravisitar.front();
		pravisitar.pop();
		
		for (auto& e:lista[x]) {
			if (visited[e] == -1) {
				visited[e] = 1;
				pravisitar.push(e);
			}
		}
	}
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M; cin >> N >> M;
	visited.assign(N, -1);
	
	for (int i=0; i<M; i++) {
		int a, b; cin >> a >> b;
		a--;
		b--;
		
		lista[a].push_back(b);
		lista[b].push_back(a);
	}
	
	int cont = 0;
	
	for (int i=0; i<N; i++) {
		if (visited[i] == -1) {
			
			cont++;
			
			bfs(i);	
		}
	}
	
	cout << cont << "\n";
	
	return 0;
}