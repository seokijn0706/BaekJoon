#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str; cin >> str;
	int sum = 0;
	int len = str.size();
	bool flag = false;
	for (int i = 0; i < len; i++) { // 음수을 한 번이라도 만나면 그 뒤에 나오는 양수는 음수로 변경
		if (str[i] == '-') flag = true;
		if (flag && str[i] == '+') str[i] = '-'; 
	}
	string value;
	
	bool minus = false; // 현재 value의 부호를 저장

	for (int i = 0; i < len; i++) {
		if (str[i] != '+' && str[i] != '-') value.push_back(str[i]); // 숫자이면 value string에 push
		else if (str[i] == '+') { // + 연산자를 만났을 때
			if (minus) { // 이전까지 저장한 value가 음수이면
				sum -= atoi(value.c_str()); // string value을 integer로 변경 후 음수 값을 축적
				value.clear(); // 사용한 value 초기화
			}
			else { // 이전까지 저장한 value가 양수이면
				sum += atoi(value.c_str()); // string value을 integer로 변경 후 양수 값을 축적
				value.clear(); // 사용한 value 초기화
			}
			minus = false; // +를 만났으니 다음에 오는 value는 양수 값
		}

		else if (str[i] == '-') { // - 연산자를 만났을 때
			if (minus) { // 이전까지 저장한 value가 음수이면
				sum -= atoi(value.c_str()); // string value을 integer로 변경 후 음수 값을 축적
				value.clear(); // 사용한 value 초기화
			}
			else { // 이전까지 저장한 value가 양수이면
				sum += atoi(value.c_str()); // string value을 integer로 변경 후 양수 값을 축적
				value.clear(); // 사용한 value 초기화
			}
			minus = true; // -를 만났으니 다음에 오는 value는 음수 값
		}
		
	}
	if (minus) { // 마지막 남은 value 처리
		sum -= atoi(value.c_str());
		value.clear();
	}
	else {
		sum += atoi(value.c_str());
		value.clear();
	}
	minus = true;
	cout << sum;
	return 0;
}
