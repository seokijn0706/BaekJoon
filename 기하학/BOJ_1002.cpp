#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int d1 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		int d2 = r1 * r1 + 2*r1 * r2 + r2 * r2;
		int d3 = r1 * r1 - 2 * r1 * r2 + r2 * r2;

		if (r1 == r2 && x1 == x2 && y1 == y2) cout << "-1\n"; // 두 원이 일치
		else if (d1 == d3) cout << "1\n"; // 내접
		else if (d1 == d2) cout << "1\n"; // 외접
		else if (d1 > d2) cout << "0\n"; // 두 원이 떨어져있음
		else if (d1 < d3) cout << "0\n"; // 원 안에 다른 원
		else cout << "2\n"; // 두 점에서 만날 때
	}

	return 0;
}
