#include <iostream>
using namespace std;

#define MAX_SIZE 100000

int parent[MAX_SIZE + 1];

int Find(int x) {
	if (parent[x] == x) { // �ڱ� �ڽŰ� ������ �θ��̹Ƿ� ����
		return x;
	}
	else {

		return parent[x] = Find(parent[x]); // �ٸ��� �θ� ã�Ƽ� ����
	}
}
void Union(int x, int y) {
	int xParent = Find(x); // x�� �θ� ã�´�
	int yParent = Find(y); // y�� �θ� ã�´�
	if (xParent < yParent) { // �� ũ�Ⱑ ���� �θ� ������ ��ġ��
		parent[yParent] = xParent; //y�� �θ� x��

	}
	else {
		parent[xParent] = yParent; //x�� �θ� y��
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int g; cin >> g;
	for (int i = 0; i <= g; i++) {
		parent[i] = i;	 // �� ó���� �ڱ� �ڽ��� �θ� ���
	}
	int p; cin >> p;
	int docking = 0;
	bool canDocking = true;
	for (int i = 0; i < p; i++) {
		int gi; cin >> gi;
		if (!canDocking) continue; //�� �̻� ��ŷ�� ���ϸ� ����
		int parent = Find(gi);
		if (parent != 0) {
			docking++;
			Union(parent, parent - 1); // ��ȣ�� 1 ���� �θ� ����.
		}
		else { //�θ� 0�̸� �� �̻� ��ŷ�� ����
			canDocking = false;
		}
	}
	cout << docking;
	return 0;
}
 