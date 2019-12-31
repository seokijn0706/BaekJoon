#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int n;

bool isPalindrome(string x) {
	string reversed = x;
	reverse(reversed.begin(), reversed.end());
	return x == reversed;
}

bool isPrime(string x) {
	int num = atoi(x.c_str());
	if (num == 1) return false; // 1이면 소수가 아님
	for (int i = 2; i * i <= n; i++) {
		if (num % i == 0) return false;
	}
	return true;

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while (true) {
		//string s = to_string(n); c++11~
		stringstream ss;
		ss << n;
		string s = ss.str();

		if (isPrime(s) && isPalindrome(s)) {
			cout << s;
			break;
		}
		else {
			n++;
		}
	}
	return 0;
}
