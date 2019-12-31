#include <iostream>
#include <map>
#include <string>
using namespace std;

#define MAX_SIZE 200000
int len = 0; // 노드 번호
int id[MAX_SIZE][2]; // [0]은 부모를 저장 [1]은 부모와 연결된 노드들의 갯수를 저장
map<string, int> m; // 이름, 노드 번호

void init() { // 초기화
	len = 0;
	m.clear();
	for (int i = 0; i < MAX_SIZE; i++) {
		id[i][0] = 0;
		id[i][1] = 0;
	}
}
int Find(int x) {
	if (id[x][0] == x) { // 자기 자신이 부모이면 자기 자신을 리턴
		return x;
	}
	else {
		return Find(id[x][0]); // 그렇지 않으면 부모를 계속 찾음
	}
}

void Union(int x, int y) {
	int xParent = Find(x); // x의 부모를 찾는다
	int yParent = Find(y); // y의 부모를 찾는다
	id[xParent][0] = yParent; // x의 부모로 y의 부모를 가진다
	id[yParent][1] += id[xParent][1]; // x를 y에 갖다 붙였으므로 x의 연결된 노드들은 최상위 부모가 된 y의 노드의 갯수에 추가
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case; cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int f; cin >> f;
		init();
		for (int j = 0; j < f; j++) {
			string person1, person2; cin>>person1 >> person2;
			if (m.find(person1) == m.end()) {  // 처음 입력 받은 이름이면
				m.insert(make_pair(person1, len)); // map에 이름과 노드번호를 삽입
				id[m[person1]][0] = len; // 처음엔 자기 자신이 부모 노드
				id[m[person1]][1] = 1; // 처음엔 자기 자신밖에 연결이 안돼있음
				len++; // 다음 노드 번호
			}
			if (m.find(person2) == m.end()) { // 처음 입력 받은 이름이면
				m.insert(make_pair(person2, len)); // map에 이름과 노드번호를 삽입
				id[m[person2]][0] = len; // 처음엔 자기 자신이 부모 노드
				id[m[person2]][1] = 1; // 처음엔 자기 자신밖에 연결이 안돼있음
				len++; // 다음 노드 번호
			}
			if (Find(id[m[person1]][0]) != Find(id[m[person2]][0])) { // 서로 다른 그래프에 있으면
				Union(id[m[person1]][0], id[m[person2]][0]); // 두 그래프를 합친다(합치면서 최상위 부모에 연결된 노드 개수 갱신)
			}
			cout << id[Find(id[m[person1]][0])][1] << "\n"; // 최상위 부모를 찾아서 그에 연결된 노드 값 출력
		}
	}
	return 0;
}
