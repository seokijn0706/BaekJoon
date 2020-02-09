#include <iostream>
#include <algorithm>
using namespace std;
//dp[i][j] = i��°���� �۱��� ��������� ����� ���� j�� �ǵ��� �ϴ� �޸��� �ִ밪
int dp[101][10001];
int b[101];
int c[101];

int main(void) {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int byte;
		cin >> byte;
		b[i] = byte;
	}
	for (int i = 1; i <= n; i++) {
		int cost;
		cin >> cost;
		c[i] = cost;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=10000; j++) {
			if (c[i] <= j) {
				dp[i][j] = max(b[i] + dp[i - 1][j - c[i]], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	for (int j = 1; j <= 10000; j++) {
		if (dp[n][j] >= m) { //m����Ʈ �̻��� �����ϴ� ���� ã����
			cout << j; //m����Ʈ�� �ش��ϴ� �ּ� ��� j�� ���
			return 0;
		}
	}
	return 0;
}