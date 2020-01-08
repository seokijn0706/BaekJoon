#include <iostream>
using namespace std;

#define MAX_SIZE 100000

int parent[MAX_SIZE + 1];

int Find(int x) {
	if (parent[x] == x) { // 자기 자신과 같으면 부모이므로 리턴
		return x;
	}
	else {

		return parent[x] = Find(parent[x]); // 다르면 부모를 찾아서 리턴
	}
}
void Union(int x, int y) {
	int xParent = Find(x); // x의 부모를 찾는다
	int yParent = Find(y); // y의 부모를 찾는다
	if (xParent < yParent) { // 더 크기가 작은 부모 쪽으로 합치기
		parent[yParent] = xParent; //y의 부모를 x로

	}
	else {
		parent[xParent] = yParent; //x의 부모를 y로
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int g; cin >> g;
	for (int i = 0; i <= g; i++) {
		parent[i] = i;	 // 맨 처음엔 자기 자신이 부모 노드
	}
	int p; cin >> p;
	int docking = 0;
	bool canDocking = true;
	for (int i = 0; i < p; i++) {
		int gi; cin >> gi;
		if (!canDocking) continue; //더 이상 도킹을 못하면 무시
		int parent = Find(gi);
		if (parent != 0) {
			docking++;
			Union(parent, parent - 1); // 번호가 1 낮은 부모에 연결.
		}
		else { //부모가 0이면 더 이상 도킹을 못함
			canDocking = false;
		}
	}
	cout << docking;
	return 0;
}
 