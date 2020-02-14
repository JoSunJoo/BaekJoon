#include<stdio.h>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> result;
int M, N, K;
int square[100][100] = { 0 };
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

bool isValid(int x, int y) {//영역 내에 존재하는가?
	return x >= 0 && x < M && y >= 0 && y < N;
}

void BFS(int a, int b) {//한 영역의 갯수 세기
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	square[a][b] = 1;
	int res = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		res++;
		for (int i = 0; i < 4; i++) {
			int X = x + dx[i], Y = y + dy[i];
			if (isValid(X, Y) && square[X][Y] == 0) {
				square[X][Y] = 1;
				q.push(make_pair(X, Y));
			}
		}
	}
	result.push_back(res);
}

int main() {
	scanf("%d %d %d", &M, &N, &K);
	while (K--) {
		int x1, y1, x2, y2;	scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		for (int i = x1; i < x2; i++) {//박스의 영역 칠하기
			for (int j = y1; j < y2; j++) square[i][j] = 1;
		}
	}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (square[i][j] == 0) {
				BFS(i, j);
			}

	sort(result.begin(), result.end());
	printf("%d\n", result.size());
	for (int i = 0; i < result.size(); i++) printf("%d ", result[i]);
	return 0;
}
