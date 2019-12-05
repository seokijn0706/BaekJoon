#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int map[1000][1000];
int visit[1000][1000][2];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int n, m;
/*좌표 클래스*/
class pos {
public:
	int x;
	int y;
	int isBreak; //한 번이라도 부셨으면 1 아니면 0
	pos(int x, int y, int isBreak) : x(x), y(y), isBreak(isBreak) {
	}
};


/*bfs로 최단거리 구하기*/
int bfs(void) {
	queue<pos> Q;
	pos p(0, 0, 0);
	Q.push(p);
	visit[0][0][0] = 1; // 방문 체크
	while (!Q.empty()) {
		pos cur = Q.front(); Q.pop(); // 큐에서 꺼냄
		if (cur.x == n - 1 && cur.y == m - 1) { // 목적지에 도착했을 경우
			if (visit[cur.x][cur.y][0] && visit[cur.x][cur.y][1])
				return min(visit[cur.x][cur.y][0], visit[cur.x][cur.y][1]);
			else if (visit[cur.x][cur.y][0])
				return visit[cur.x][cur.y][0];
			else
				return visit[cur.x][cur.y][1];
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue; //배열 범위 넘어가면 무시
			if (cur.isBreak == 0) { // 이전에 벽을 안 부쉈을 경우
				if (map[nx][ny] == 1) { // 벽을 만났을 때
					if (visit[nx][ny][1]) continue;
					visit[nx][ny][1] = visit[cur.x][cur.y][0] + 1; // 벽을 부셔서 이동한 경우 방문체크
					pos np(nx, ny, 1); // 벽 부신 상태를
					Q.push(np); // 큐에 삽입
				}
				else { // 벽을 만나지 않았을 떄
					if (visit[nx][ny][0]) continue;
					visit[nx][ny][0] = visit[cur.x][cur.y][0] + 1; // 그냥 이동한 경우 방문체크
					pos np(nx, ny, 0); // 벽 부신 상태를
					Q.push(np); // 큐에 삽입
				}
			}
			else { // 이전에 벽을 부쉈을 경우
				if (map[nx][ny] == 1) { // 벽을 만났을 때
					continue;
				}
				else {	// 벽을 만나지 않았을 때
					if (visit[nx][ny][1]) continue;
					visit[nx][ny][1] = visit[cur.x][cur.y][1] + 1; // 그냥 이동한 경우 방문 체크
					pos np(nx, ny, 1); // 벽 부신 상태 + 이동한 거리를
					Q.push(np); // 큐에 삽입
				}
			}
		}
	}
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	cout << bfs();

}
