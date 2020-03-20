#include <iostream>
#include <vector>
using namespace std;

bool visited[1001];
vector<vector<int> > adj(1001);
int n, m;

void dfs(int cur) {
	for (auto& next : adj[cur]) {
		if (visited[next])continue;
		visited[next] = true;
		dfs(next);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i])continue;
		dfs(i);
		cnt++;
	}
	cout << cnt;

	return 0;
}
