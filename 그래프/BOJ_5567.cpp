#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int visited[501];
vector<vector<int> > adj(501);
int cnt = 0;

void bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto& next : adj[cur]) {
			if (visited[next] || visited[cur] >= 3)continue;
			q.push(next);
			visited[next] = visited[cur] + 1;
			cnt++;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs();
	cout << cnt;
	

	return 0;
}
