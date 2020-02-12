#include <iostream>
using namespace std;


/*�Ҽ� �Ǻ� �Լ�*/
bool is_prime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++) { //o(sqrt(n))
		if (n % i == 0) return false;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		int n; cin >> n;
		if (!n) return 0; // 0 �Է½� ����
		int st = 3; //b-a�� ���� �ּ�
		int en = n - 3;
		bool flag = true;
		while (flag) {
			if (is_prime(st) && is_prime(en)) { // �Ѵ� �Ҽ��̸�
				cout << n << " = " << st << " + " << en << "\n";
				flag = false; // ���Ŀ� �°� ��� �� ����
			}
			else { // �׷��� ������ ������ ����
				st++;
				en--;
			}
			if (st > en) flag = false;  // ��� Ȯ�������� ����
		}
	}

	return 0;
}