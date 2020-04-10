#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[1001];
vector<int> res;
int indegree[1001];
void solve() {
	queue<int> q;
	for (int i = 1; i <= n; i++) if (!indegree[i]) q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		res.push_back(cur);
		for (auto& next : adj[cur]) {
			indegree[next]--;
			if (!indegree[next]) q.push(next);
			
		}
	}
	if (res.size() != n) { //사이클이 존재하면
		res.clear();
		res.push_back(0);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	while (m--) {
		int num;
		cin >> num;
		int prev;
		cin >> prev;
		num--;
		while (num--) {
			int cur;
			cin >> cur;
			adj[prev].push_back(cur);
			indegree[cur]++;
			prev = cur;
		}
	}
	solve();
	for (auto& e : res) cout << e << '\n';

	return 0;
}
