#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int indegree[32001];
vector<int> adj[32001];
vector<int> res;
int n, m;

void solve() {
	queue<int> q;
	for (int i = 1; i <= n; i++) if (!indegree[i]) q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		res.push_back(cur);
		for (auto& next : adj[cur]) {
			indegree[next]--;
			if (!indegree[next])q.push(next);
		}
	}
	
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++;
	}
	solve();

	for (auto& e : res) {
		cout << e << " ";
	}


	return 0;
}
