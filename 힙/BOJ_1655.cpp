#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int m;
	cin >> m;
	int data;
	int mid;
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int> > min_pq;
	vector<int> ans;
	cin >> data;
	mid = data;
	ans.push_back(mid); //1개 일때는 그 수가 mid
	for (int i = 2; i <= m; i++) {
		cin >> data;
		if (data < mid)max_pq.push(data); //data를 mid 보다 작으면 최대힙 크면 최소힙에 넣는다
		else min_pq.push(data);
		int max_pq_size = max_pq.size();
		int min_pq_size = min_pq.size();
		if (i % 2 == 1) { //홀수 번째 수를 읽을 때 마다
			if (max_pq_size < min_pq_size) { //최대 힙과 최소 힙 중에 사이즈가 작은 힙에 mid를 push
				max_pq.push(mid);
				max_pq_size++;
			}
			else {
				min_pq.push(mid);
				min_pq_size++;
			}

			if (max_pq_size > min_pq_size) { // 힙 중에 사이즈가 큰 힙의 top이 mid가 됨
				mid = max_pq.top();
				max_pq.pop();
			}
			else {
				mid = min_pq.top();
				min_pq.pop();
			}
			ans.push_back(mid);
		}
		else {//짝수 번쨰 수를 읽을 때는 최대 힙과 최소 힙중에 사이즈가 큰 쪽의 top과 mid중 작은값을 출력
			if (max_pq_size > min_pq_size) ans.push_back(min(max_pq.top(), mid));
			else ans.push_back(min(min_pq.top(), mid));
		}
	}
	for (auto& e : ans) cout << e << "\n";

	return 0;
}
