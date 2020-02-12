#include <iostream>
using namespace std;


/*소수 판별 함수*/
bool is_prime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++) { //o(sqrt(n))
		if (n % i == 0) return false;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		int n; cin >> n;
		if (!n) return 0; // 0 입력시 종료
		int st = 3; //b-a가 가장 최소
		int en = n - 3;
		bool flag = true;
		while (flag) {
			if (is_prime(st) && is_prime(en)) { // 둘다 소수이면
				cout << n << " = " << st << " + " << en << "\n";
				flag = false; // 형식에 맞게 출력 후 종료
			}
			else { // 그렇지 않으면 간격을 좁힘
				st++;
				en--;
			}
			if (st > en) flag = false;  // 모두 확인했으면 종료
		}
	}

	return 0;
}