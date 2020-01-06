#include <iostream>
using namespace std;

#define MAX 1000

int prime[MAX + 1];

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
int main(void) {
	cin >> n;
	updatePrime();
	int count = 0;
	for (int i = 0; i < n; i++) {
		int data; cin >> data;
		if (prime[data])count++;
	}
	cout << count;
	return 0;
}
