#include<stdio.h>
#include<queue>
#include<utility>
#include<iostream>
using namespace std;

int N;
char arr[102][102];
int visited1[102][102] = { 0 }, visited2[102][102] = { 0 };
int normal = 0, n_normal = 0;
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
bool isValid(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

void BFS(int x, int y) { //정상
	queue<pair<int, int>> q;
	char now = arr[x][y];
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (visited1[X + dx[i]][Y + dy[i]] == 0 && arr[X + dx[i]][Y + dy[i]] == now) {
				visited1[X + dx[i]][Y + dy[i]] = 1;
				q.push(make_pair(X + dx[i], Y + dy[i]));
			}
		}
	}
	normal++;
}

void BFS1(int x, int y) { //적록색약
	queue<pair<int, int>> q;
	char now = arr[x][y];
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (visited2[X + dx[i]][Y + dy[i]] == 0) {
				if (now == 'R' || now == 'G') {
					if (arr[X + dx[i]][Y + dy[i]] == 'R' || arr[X + dx[i]][Y + dy[i]] == 'G') {
						visited2[X + dx[i]][Y + dy[i]] = 1;
						q.push(make_pair(X + dx[i], Y + dy[i]));
					}
				}
				else {
					if (arr[X + dx[i]][Y + dy[i]] == now) {
						visited2[X + dx[i]][Y + dy[i]] = 1;
						q.push(make_pair(X + dx[i], Y + dy[i]));
					}
				}
			}
		}
	}
	n_normal++;
}


int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited1[i][j] == 0) BFS(i, j);
			if (visited2[i][j] == 0) BFS1(i, j);
		}
	}
	printf("%d %d", normal, n_normal);
	return 0;
}
