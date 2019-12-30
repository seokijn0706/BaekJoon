#include <iostream>
using namespace std;

#define MAX_SIZE 201

int city[MAX_SIZE]; // 도시 정보 1 ~ 200

int Find(int x) {
	if (city[x] == x) { //자기 자신이 부모이면
		return x; // 자기 자신을 리턴
	}
	else {
		return city[x] = Find(city[x]); //부모를 찾아서 리턴
	}
}

void Union(int x, int y) {
	int xParent = Find(x); // x의 부모를 찾는다
	int yParent = Find(y); // y의 부모를 찾는다
	city[xParent] = yParent; //x에 y를 이어 붙인다.
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		city[i] = i; // 처음엔 자기 자신이 부모
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int isConnection; cin >> isConnection;
			if (isConnection) { // i 노드와  j노드가 서로 연결 되어있으면
				Union(i, j); //i 와 j를 이어 붙임
			}
		}
	}
	int path; cin >> path;
	int root = Find(path); // 초기 부모 값
	for (int i = 1; i < m; i++) {
		cin >> path;
		if (root != Find(path)) { //하나라도 연결이 안돼있으면
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
