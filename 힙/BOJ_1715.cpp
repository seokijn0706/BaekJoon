#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > pq;
	while (n--) {
		int num;
		cin >> num;
		pq.push(num);
	}
	int cnt = 0;
	while (pq.size() != 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		cnt += a + b;
		pq.push(a + b);
	}
	cout << cnt;

	return 0;
}
