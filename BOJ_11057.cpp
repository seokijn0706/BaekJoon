#include <iostream>
using namespace std;

int dp[1000][10]; // 최대 길이가 1000, 정수 0 <= k <= 9

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int k = 0; k <= 9; k++) {
		dp[0][k] = 1; //길이가 1일 때 0 번째 인덱스에 정수 k가 나오는 모든 경우의 수는 1 
	}
	for (int i = 1; i < n; i++) {
		for (int k = 0; k <= 9; k++) {
			for (int a = 0; a <= k; a++) {
				dp[i][k] = (dp[i][k] + dp[i - 1][a]) % 10007; // i 번째 인덱스까지 고려했을 때 정수 k가 나오는 경우의 수는
															  // i - 1번째 인덱스까지 고려했을 때 k보다 작거나 같은 정수A가 나오는 모든 경우의 수의 합
			}
		}
	}
	int sum = 0;
	for (int k = 0; k <= 9; k++) {
		sum = (sum + dp[n - 1][k]) % 10007; // n - 1 번째 인덱스까지 고려했을 때 정수 k가 나오는 모든 경우의 수의 합
	}
	cout << sum;

	return 0;
}
