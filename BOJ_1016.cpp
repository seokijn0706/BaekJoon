#include <iostream>
using namespace std;

typedef long long int ll;

ll nonoSquare[1000001];

int solution(ll min, ll max) {
	ll answer = 0;
	for (ll i = 0; i <= max - min; i++) {
		nonoSquare[i] = true; // 처음엔 모두가 ㄴㄴ 제곱수
	}
	for (ll i = 2; i * i <= max; i++) {
		ll squareNum = i * i;
		ll k = min / squareNum; //min부터 시작하는 배수
		if (squareNum * k != min) k++; // min과 같은 배수가 안되면 1증가시켜서 맞춰줌
		while (squareNum * k <= max) { // 제곱수의 배수가 max를 안넘기면
			nonoSquare[squareNum * k - min] = false; // 제곱수의 배수를 false
			k++;
		}
	}
	for (int i = 0; i <= max - min; i++) {
		if (nonoSquare[i]) { // ㄴㄴ제곱수이면
			answer++;
		}
	}
	return answer;
}

int main(void) {
	ll min, max; cin >> min >> max;

	cout << solution(min, max);

	return 0;
}
