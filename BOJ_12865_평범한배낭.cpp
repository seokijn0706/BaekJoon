#include <iostream>
#include <algorithm>
using namespace std;

int w[101];
int v[101];
int dp[101][100001];

int main(void) {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int weight, value; cin >> weight >> value;
		w[i] = weight;
		v[i] = value;
	}

	for (int i = 1; i <= n; i++) { // 2��°����
		for (int j = 1; j <= k; j++) { // ���� 1 ~ k�� �ɶ�
			if (w[i] <= j) { //���԰� ���� ���� ������
				dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]); // i��°������ ������ ����ؼ� ���� j�� ����Ͱ� i-1��°������ ������ ����ؼ� ���� j�� ������� max
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][k];
	return 0;
}