#include <iostream>
using namespace std;

#define NORTH 0 // 북쪽
#define EAST 1 // 동쪽
#define SOUTH 2 // 남쪽
#define WEST 3 // 서쪽

int n, m;
int r, c, d;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int map[50][50];
int cnt;
void clear(int cx, int cy, int dir) {
	if (map[cx][cy] == 0) {
		cnt++;
		map[cx][cy] = 2; //현재 위치를 청소한다.
	}
	for (int i = 0; i < 4; i++) { // 4방향 탐색 가능
		if (dir == 0)dir = 3;
		else dir--;  //현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 탐색
		int nx = cx + dx[dir];
		int ny = cy + dy[dir]; //왼쪽 방향
		if (map[nx][ny] == 0) { // 아직 청소하지 않는 공간이 존재한다면
			clear(nx, ny, dir); // 그 방향으로 회전한 다음 한 칸 전진
			return;
		}
		if (map[nx][ny]) {
			continue; // 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
		}
	}
	//네 방향 모두 청소가 이미 되어있거나 벽인 경우에는
	int temp_dir; // 바라보는 방향 유지를 위한 temp_dir
	if (dir == 0) temp_dir = 2;
	if (dir == 2) temp_dir = 0;
	if (dir == 1) temp_dir = 3;
	if (dir == 3) temp_dir = 1;
	int nx = cx + dx[temp_dir];
	int ny = cy + dy[temp_dir]; //다음 방향
	if (map[nx][ny] == 1) return; // 만약 모두 청소 + 벽이면 작동 멈춤
	clear(nx, ny, dir); // 방향 유치한 채로 한 칸 후진
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	clear(r, c, d);
	cout << cnt;

	return 0;
}
