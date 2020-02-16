#include<stdio.h>
#include<queue>
#include<utility>
using namespace std;

int arr[100][100] = { 0 };
int N, R, C;
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
bool isValid(int x, int y) {
	return x >= 1 && x <= N && y >= 1 && y <= N;
}

void BFS(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	arr[a][b] = 2;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int X = x + dx[i], Y = y + dy[i];
			if (isValid(X, Y) && arr[X][Y] == 0) {
				arr[X][Y] = 1;
				if (isValid(X + 1, Y) && arr[X + 1][Y] == 0) {
					arr[X + 1][Y] = 2;
					q.push(make_pair(X+1, Y));
				}
				if (isValid(X - 1, Y) && arr[X - 1][Y] == 0) {
					arr[X - 1][Y] = 2;
					q.push(make_pair(X-1, Y));
				}
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &R, &C);
	BFS(R, C);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1) printf(".");
			else printf("v");
		}
		printf("\n");
	}
	return 0;
}
