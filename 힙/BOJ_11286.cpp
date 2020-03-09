#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> pib;

pair<int, int> p;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	priority_queue<pib, vector<pib>, greater<pib> > pq;

	while (n--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top().second << "\n";
				pq.pop();
			}
			else {
				cout << "0\n";
			}
		}
		else {
			pq.push({ abs(x), x });
		}
	}
	
	return 0;
}
