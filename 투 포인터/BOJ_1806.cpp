#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int arr[100000];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int l = 0, r = 0, sum = 0, res = n;
	bool existence = false;
	while (true) {
		if (sum >= s && s) {
			existence = true;
			res = min(res, r - l);
			sum -= arr[l++];
		}
		else if (r == n) break;
		else sum += arr[r++];
	}
	if (existence) cout << res;
	else cout << 0;
	return 0;
}
