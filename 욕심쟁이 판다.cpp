#include<stdio.h>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

/*
알고리즘 : DP + DFS
1. DFS를 사용해서 해당 좌표에서 갈 수 있는 최대값을 찾기
2. DFS()함수가 반환될 때, 탐색한 경로의 좌표마다 갈 수 있는 최대값을 dp에 저장함
=> 시간 단축!!!!!
*/

int N, result = 0;
int arr[501][501];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int dp[501][501];

bool isVaild(int x, int y) {//범위 내에 존재하는가?
	return x >= 0 && x < N && y >= 0 && y < N;
}

int DFS(int x, int y, int len) {//DFS를 사용해서 갈 수 있는 경로 탐색
	int res = len;
	if (dp[x][y] != -1) return dp[x][y] + len - 1;//memo사용해서 중복 탐색 방지(탐색한 길에 대한 정보를 저장해놓음)
	for (int i = 0; i < 4; i++) {//동서남북으로 탐색
		int X = x + dx[i], Y = y + dy[i];
		if (isVaild(X, Y) && arr[x][y] < arr[X][Y])
			res = max(DFS(X, Y, len + 1), res);
	}
	dp[x][y] = res - len + 1;//현재 탐색하는 위치에서 갈 수 있는 최대값 저장
	return res;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		scanf("%d", &arr[i][j]);
		dp[i][j] = -1;
	}

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		if (dp[i][j] == -1) {
			dp[i][j] = DFS(i, j, 1);
			result = max(dp[i][j], result);
		}
	}
	printf("%d", result);

	return 0;
}
