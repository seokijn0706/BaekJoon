#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;



int n, m;
int arr[1000001];

int Find(int x) {
	if (arr[x] == x) { // 자기 자신과 같으면 부모이므로 리턴
		return x;
	}
	else {
		
		return arr[x] = Find(arr[x]); // 다르면 부모를 찾아서 리턴
	}
}
void Union(int x, int y) {
	int xParent = Find(x); // x의 부모를 찾는다
	int yParent = Find(y); // y의 부모를 찾는다
	if (xParent < yParent) { // 더 크기가 작은 부모 쪽으로 합치기
		arr[yParent] = xParent; //y의 부모를 x로
	}
	else {
		arr[xParent] = yParent; //x의 부모를 y로
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		arr[i] = i;	 // 맨 처음엔 자기 자신이 부모 노드
	}
	for (int i = 0; i < m; i++) {
		int flag, a, b; cin >>flag>> a >> b;
		if (flag) {
			if (Find(a) == Find(b)) { //a, b 부모가 같으면
				cout << "YES\n";
			}
			else { // 다르면
				cout << "NO\n";
			}
		}
		else {
			Union(a, b); // a, b 두 집합을 합집합
		}
	}

	return 0;
}
