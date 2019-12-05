#include <iostream>
#include <cstring>
using namespace std;

int map[300][300];
int before_melting[300][300];
int visit[300][300];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int n, m;
int year;
void copy() {
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			before_melting[i][j] = map[i][j];
		}
	}
}
/*dfs로 빙하 갯수 세기*/
void dfs(int cx, int cy) {
	visit[cx][cy] = 1; //현재 좌표 방문 체크
	for (int dir = 0; dir < 4; dir++) {
		int nx = cx + dx[dir];
		int ny = cy + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue; //배열 인덱스 벗어나면 무시
		if (map[nx][ny] <= 0) continue; // 바닷물이면 무시
		if (visit[nx][ny])continue; //이미 방문했으면 무시
		dfs(nx, ny); // 다음 좌표에서 다시 dfs
	}
}
/*빙하 녹이기*/
void melt_ice() {
	int surrounding_sea = 0; // 주면 바다 개수
	copy();
	for (int cx = 0; cx < n; cx++) {
		for (int cy = 0; cy  < m; cy++) {
			if (before_melting[cx][cy] <= 0) continue; // 현재 좌표가 바닷물이면 무시
			for (int dir = 0; dir < 4; dir++) {
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue; //배열 인덱스 벗어나면 무시
				if (before_melting[nx][ny] <= 0) { // 주변이 바닷물이면
					surrounding_sea++;  // 바닷물 갯수 카운트
				}
			}
			map[cx][cy] -= surrounding_sea; //주변 바닷물 갯수 만큼 빙하 녹이기
			surrounding_sea = 0; // 바닷물 갯수 초기화
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	bool flag = true;  // 얼음을 녹이기 위한 while 플래그
	int cnt = 0; // 분리돼 있는 빙하 갯수
	for (int cx = 0; cx < n; cx++) {
		for (int cy = 0; cy < m; cy++) { //모든 좌표 탐색
			if (map[cx][cy] <= 0 || visit[cx][cy]) continue; // 바닷물이거나 이미 방문했으면 무시 (빙하를 녹이다 보면 바닷물도 음수가 될 수 있음)
			dfs(cx, cy);
			cnt++; // dfs를 호출한 횟수가 결국 분리된 빙하 갯수
		}
	}
	if (cnt == 0 || cnt == 2) flag =false; // 처음부터 빙하가 없거나(0) 분리 돼있으면(2) 얼음을 녹일 필요도 없이 끝  

	while (flag) { // flag가 참이면 빙하를 녹여보며 분리된 갯수 check
		memset(visit, 0, sizeof(visit));	// 매번 녹이기 전에 visit 배열 초기화 필수
		cnt = 0; // 분리된 갯수 초기화 필수
		melt_ice(); // 녹이고
		year++; // 녹일 때마다 1년 증가
		for (int cx = 0; cx < n; cx++) {
			for (int cy = 0; cy < m; cy++) {  // 모든 좌표 탐색
				if (map[cx][cy] <= 0 || visit[cx][cy]) continue; // 바닷물이거나 이미 방문했으면 무시 (빙하를 녹이다 보면 바닷물도 음수가 될 수 있음)
				dfs(cx, cy);  
				cnt++;  // dfs를 호출한 횟수가 결국 분리된 빙하 갯수
				if (cnt == 2) { // 분리가 된 걸 확인한 순간
					cout << year; // 경과한 year을 출력 후
					return 0; // 프로그램 종료
				}
			}
		}
		if (cnt == 0) { // 모든 좌표를 탐색 했는데도 분리된 빙하가 없다면
			flag = false; // 더 이상 녹일 필요가 없으므로 while문 종료를 위한 flag False
			year = 0; // 분리된 빙하가 없으므로 year == 0
		}
	}
	cout << year; // flag == false가 됐을 때 year 출력

	return 0;
}
