#include<stdio.h>
#include<iostream>
#include<tuple>
#include<queue>
#include<algorithm>
#include<queue>
using namespace std;

int N, M;
int arr[1001][1001];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
int visited[1001][1001][2];

bool isValid(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

int BFS() {
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 1));
	visited[0][0][1] = 1;

	int cnt = 0;
	while (!q.empty()) {
		int x, y, check;
		x = get<0>(q.front());   y = get<1>(q.front());  check = get<2>(q.front());
		q.pop();

		if (x == N - 1 && y == M - 1) return visited[x][y][check];

		for (int i = 0; i < 4; i++) {
			int X = x + dx[i], Y = y + dy[i];
			if (isValid(X, Y) && arr[X][Y] == 1 && check == 1) {
				visited[X][Y][check-1] = visited[x][y][check] + 1;
				q.push(make_tuple(X, Y,check-1));
			}
			else if (isValid(X, Y) && arr[X][Y] == 0 && visited[X][Y][check] == 0) {
				visited[X][Y][check] = visited[x][y][check] + 1;
				q.push(make_tuple(X, Y, check));
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &N, &M);
	char c;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		cin >> c;
		arr[i][j] = c - '0';
	}

	printf("%d", BFS());
	return 0;
}
