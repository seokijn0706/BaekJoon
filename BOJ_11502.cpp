#include <iostream>
using namespace std;

#define MAX 1000

int prime[MAX + 1];
int visit[MAX + 1];
int res[3];
void updatePrime() {
	for (int i = 2; i <= MAX; i++) {
		prime[i] = true;
	}
	for (int i = 2; i * i <= MAX; i++) {
		if (!prime[i]) continue;
		for (int j = i * i; j <= MAX; j += i) {
			prime[j] = false;
		}
	}
}

int n;
int k;
int flag = true;
void dfs(int depth) {
	if (!flag) return;
	if (depth == 3) {
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += res[i];
		}
		if (sum == k) {
			for (int i = 0; i < 3; i++) {
				cout << res[i] << " ";
			}
			cout << "\n";
			flag = false;
			return;
		}
		return;

	}
	for (int i = 2; i <= k; i++) {
		if (!prime[i]) continue; //소수가 아니면 무시
		res[depth] = i;
		dfs(depth + 1);
	}
}
int main(void) {
	int test_case; cin >> test_case;
	updatePrime();
	for (int i = 0; i < test_case; i++) {
		cin >> k;
		flag = true;
		dfs(0);
	}
	return 0;
}
