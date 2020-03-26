#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int>adj[100001];
int parents[100001];
int n;

void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto& next : adj[cur]) {
			if (parents[cur] == next)continue;
			q.push(next);
			parents[next] = cur;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs();

	for (int i = 2; i <= n; i++) {
		cout << parents[i] << '\n';
	}

	return 0;
}
