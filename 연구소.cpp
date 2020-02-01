#include<stdio.h>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
int N, M;
int map[8][8] = {0};
int result = 0;


bool isValid(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

void BFS() {
	int copy[8][8];
	queue<pair<int, int>> virus;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			copy[i][j] = map[i][j];
			if (copy[i][j] == 2) virus.push(make_pair(i, j));
		}
	int dx[4] = { -1, 0, 1, 0 }, dy[4] = {0, 1, 0, -1};
	int x, y;
	while (!virus.empty()) {
		x = virus.front().first;
		y = virus.front().second;
		virus.pop();
		for (int i = 0; i < 4; i++) {
			if (isValid(x + dx[i], y + dy[i]) && copy[x + dx[i]][y + dy[i]] == 0) {
				copy[x + dx[i]][y + dy[i]] = 2;
				virus.push(make_pair(x+dx[i], y+dy[i]));
			}
		}
	}

	int temp = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		if (copy[i][j] == 0) temp++;
	}
	result = max(result, temp);
}


void DFS(int cnt) {
	if (cnt == 3) {
		BFS();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				DFS(cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
		scanf("%d", &map[i][j]);

	DFS(0);
	printf("%d", result);
	return 0;
}
