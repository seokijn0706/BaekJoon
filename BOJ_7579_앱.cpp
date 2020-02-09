#include <iostream>
#include <algorithm>
using namespace std;
//dp[i][j] = i번째까지 앱까지 고려했을때 비용의 합이 j가 되도록 하는 메모리의 최대값
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
		if (dp[n][j] >= m) { //m바이트 이상을 만족하는 값을 찾으면
			cout << j; //m바이트에 해당하는 최소 비용 j를 출력
			return 0;
		}
	}
	return 0;
}