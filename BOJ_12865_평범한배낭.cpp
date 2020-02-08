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

	for (int i = 1; i <= n; i++) { // 2번째부터
		for (int j = 1; j <= k; j++) { // 합이 1 ~ k가 될때
			if (w[i] <= j) { //무게가 합을 넘지 않으면
				dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]); // i번째까지의 물건을 사용해서 합을 j로 만든것과 i-1번째까지의 물건을 사용해서 합을 j로 만든것의 max
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][k];
	return 0;
}