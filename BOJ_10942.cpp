#include <iostream>
using namespace std;

int arr[2001];
bool dp[2001][2001]; //dp[i][j] i ~ j�� �Ӹ�����ΰ�?

int main(void) {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int data;
		cin >> data;
		arr[i] = data;
	}
	for (int i = 1; i <= n; i++) {
		int s;
		/*Ȧ��*/
		s = i;
		for (int e = i; e <= n; e++) {
			if (s <1 || e>n) break; // ���� ������ ����� ����
			if (arr[s] == arr[e]) dp[s][e] = true; // �Ӹ�����̸� true
			else break; // �Ӹ������ �ƴϸ� ����
			s--; // s�� �������� �̵�
		}
		/*¦��*/
		s = i + 1;
		for (int e = i; e <= n; e++) {
			if (s <1 || e>n) break; // ���� ������ ����� ����
			if (arr[s] == arr[e]) dp[s][e] = true; // �Ӹ�����̸� true
			else break; // �Ӹ������ �ƴϸ� ����
			s--; // s�� �������� �̵�
		}
	}
	int m;
	cin >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}
}