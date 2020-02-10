#include <iostream>
using namespace std;

int arr[2001];
bool dp[2001][2001]; //dp[i][j] i ~ j가 팰린드롬인가?

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
		/*홀수*/
		s = i;
		for (int e = i; e <= n; e++) {
			if (s <1 || e>n) break; // 수열 범위를 벗어나면 종료
			if (arr[s] == arr[e]) dp[s][e] = true; // 팰린드롬이면 true
			else break; // 팰린드롬이 아니면 종료
			s--; // s를 왼쪽으로 이동
		}
		/*짝수*/
		s = i;
		for (int e = i + 1; e <= n; e++) {
			if (s <1 || e>n) break; // 수열 범위를 벗어나면 종료
			if (arr[s] == arr[e]) dp[s][e] = true; // 팰린드롬이면 true
			else break; // 팰린드롬이 아니면 종료
			s--; // s를 왼쪽으로 이동
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
