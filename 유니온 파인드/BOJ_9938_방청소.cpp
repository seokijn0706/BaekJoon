#include <iostream>
using namespace std;

int node[300001];
bool visited[300001];

int Find(int x) {
	if (x == node[x]) return x;
	return node[x] = Find(node[x]);
}

void Union(int x, int y) {
	int xParents = Find(x);
	int yParents = Find(y);
	node[xParents] = yParents;
}

int main(void) {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, L;
	
	cin >> N >> L;
	
	for (int i = 1; i <= L; i++) {
		node[i] = i;
	}

	while (N--) {
		int a, b;
		cin >> a >> b;
		if (!visited[a]) {
			visited[a] = true;
			Union(a, b); //a의 부모를 b로
			cout << "LADICA\n";
		}
		else if (!visited[b]) {
			visited[b] = true;
			Union(b, a); //b의 부모를 a로
			cout << "LADICA\n";
		}
		else if (!visited[Find(node[a])]) {
			visited[Find(node[a])] = true; 
			Union(a, b); //a의 부모를 b로
			cout << "LADICA\n";
		}
		else if (!visited[Find(node[b])]) {
			visited[Find(node[b])] = true;
			Union(b, a); //b의 부모를 a로
			cout << "LADICA\n";
		}
		else {
			cout << "SMECE\n";
		}
	}

	return 0;
}
