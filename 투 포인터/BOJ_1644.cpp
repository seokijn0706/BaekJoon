#include <iostream>
#include <vector>
using namespace std;

bool visited[4000001];
bool is_prime[4000001];
vector<int> plist;
int n;
void eratosthenes() {
	for (int i = 2; i <= n; i++) is_prime[i] = true;
	for (int i = 2; i * i <= n; i++) {
		if (!is_prime[i]) continue;
		for (int j = i * i; j <= n; j += i) {
			is_prime[j] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	eratosthenes();
	for (int i = 2; i <= n; i++) if (is_prime[i]) plist.push_back(i);
	int s = 0, e = 0, res = 0, sum = 0;
	int psize = plist.size();
	while (true) {
		if (sum == n) res++;
		if (sum >= n) sum -= plist[s++];
		else if (e == psize) break;
		else sum += plist[e++];
	}
	cout << res;

	return 0;
}
