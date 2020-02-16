#include<stdio.h>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

int N, M, K;
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
int arr[101][101] = { 0 };
int res = 0;
bool isVaild(int x, int y) {
	return x >= 1 && x <= N && y >= 1 && y <= M;
}
void BFS(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	arr[a][b] = 0;
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int X = x + dx[i], Y = y + dy[i];
			if (isVaild(X, Y) && arr[X][Y] == 1) {
				arr[X][Y] = 0;
				q.push(make_pair(X, Y));
			}
		}
	}
	res = max(res, cnt);
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	while (K--) {
		int a, b;	scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 1) BFS(i, j);
		}
	}
	printf("%d", res);
	return 0;
}
