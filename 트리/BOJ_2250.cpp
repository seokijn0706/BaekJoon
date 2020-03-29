#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n;
int lc[10001];
int rc[10001];
int level[10001];
bool isRoot[10001];
vector<int> col;


int getRoot() {
	for (int i = 1; i <= n; i++) {
		if (lc[i] != -1) isRoot[lc[i]] = false;
		if (rc[i] != -1) isRoot[rc[i]] = false;
	}
	for (int i = 1; i <= n; i++) if (isRoot[i]) return i;
}

/*레벨 순회*/
void bfs(int root) {
	queue<int> q;
	q.push(root);
	level[root] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (lc[cur] != -1) {
			q.push(lc[cur]);
			level[lc[cur]] = level[cur] + 1;
		};
		if (rc[cur] != -1) {
			q.push(rc[cur]);
			level[rc[cur]] = level[cur] + 1;
		}
	}
}

/*중위 순회*/
void inorder(int root) {
	if (lc[root] != -1) inorder(lc[root]);
	col.push_back(root);
	if (rc[root] != -1)inorder(rc[root]);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	fill(lc, lc + 10001, -1);
	fill(rc, rc + 10001, -1);

	for (int i = 0; i < n; i++) {
		int v, l, r;
		cin >> v >> l >> r;
		lc[v] = l;
		rc[v] = r;
		isRoot[v] = true; //처음엔 모든 정점을 root로 가정
	}


	int root = getRoot();
	bfs(root); // 레벨 순회
	col.push_back(0); // 열 인덱스를 1부터 사용하기 위함
	if (lc[root] != -1) inorder(lc[root]); // 루트의 왼쪽 노드 col 벡터에 추가
	col.push_back(root); // root 노드 col 벡터에 추가
	if (rc[root] != -1) inorder(rc[root]); // 루트의 오른쪽 노드 col 백터에 추가

	int size = col.size();
	int width = 0;
	int min_level = 10000;

	for (int s = 1; s < size; s++) {
		for (int e = size - 1; e >= s; e--) {
			if (level[col[s]] == level[col[e]]) {
				if (e - s + 1 == width) {
					width = e - s + 1;
					min_level = min(min_level, level[col[s]]);
				}
				else if (e - s + 1 > width) {
					min_level = level[col[s]];
					width = e - s + 1;
				}
				break;
			}
		}
	}

	cout << min_level << " " << width;
	return 0;
}
