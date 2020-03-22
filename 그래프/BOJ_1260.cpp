#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool visited[1001];
vector<vector<int> > adj(1001);
int n, m, start;

void dfs(int cur) {
	cout << cur << " ";
	visited[cur] = true;
	for (auto& next : adj[cur]) {
		if (visited[next])continue;
		dfs(next);
	}
}
void bfs(int cur) {
	queue<int> q;
	q.push(cur);
	visited[cur] = true;
	while (!q.empty()) {
		cur = q.front();
		cout << cur << " ";
		q.pop();
		for (auto& next : adj[cur]) {
			if (visited[next])continue;
			q.push(next);
			visited[next] = true;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> start;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());

	dfs(start);

	cout << "\n";
	fill(visited, visited + 1001, 0);
	
	bfs(start);


	return 0;
}
