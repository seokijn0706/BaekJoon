#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[101];
vector<vector<int> > adj(101);
int cnt = 0;
void dfs(int cur) {
	visited[cur] = true;
	for (auto& next : adj[cur]) {
		if (visited[next]) continue;
		dfs(next);
		cnt++;
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

	dfs(1);
	cout << cnt;
	

	return 0;
}
