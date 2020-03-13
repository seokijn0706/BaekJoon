#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX (long long)2 << 31
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int k, n;
	cin >> k >> n;
	priority_queue<long long, vector<long long>, greater<long long> > pq;
	vector<int> plist;
	for (int i = 0; i < k; i++) {
		int p;
		cin >> p;
		plist.push_back(p);
		pq.push(p);
	}
	int cnt = 0;
	long long prev = 0;
	while (cnt != n) {
		long long cur = pq.top();
		pq.pop();
		if (prev == cur) continue;
		cnt++;
		for (auto& p : plist) {
			if ((long long)p * cur >= MAX)break;
			pq.push(p * cur);
			if (cur % p == 0) break;
		}
		prev = cur;
	}
	cout << prev;

}
