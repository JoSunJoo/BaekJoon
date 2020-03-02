#include<stdio.h>
#include<queue>
#include<utility>
#include<iostream>
using namespace std;

int R, C;
char arr[52][52];
int visited[52][52] = { 0 }; //몇번째로 방문했는지 
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
int go_x, go_y, gool_x, gool_y; //go:시작점, gool: 도착점
queue<pair<int, int>> river;//물이 있는 지역

bool isValid(int x, int y) {//범위를 넘지 않는가?
	return x >= 0 && x < R && y >= 0 && y < C;
}

int BFS(int a, int b) {
	queue<pair<int, int>> q;//고슴도치 위치
	q.push(make_pair(a, b));
	visited[a][b] = 1;

	while (!q.empty()) {
		int s = river.size();//물을 한칸씩 번지게 하기
		for (int i = 0; i < s; i++) {
			int x = river.front().first, y = river.front().second;
			river.pop();
			for (int i = 0; i < 4; i++) {
				int X = x + dx[i], Y = y + dy[i];
				if (isValid(X, Y) && arr[X][Y] == '.') {
					river.push(make_pair(X, Y));
					arr[X][Y] = '*';
				}
			}
		}

		s = q.size();//고슴도치가 이동할 수 있는곳을 탐색하기
		for (int i = 0; i < s; i++) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			
			if (x == gool_x && y == gool_y) return visited[x][y] - 1;
			for (int j = 0; j < 4; j++) {
				int X = x + dx[j], Y = y + dy[j];
				if (isValid(X, Y)) {
					if (arr[X][Y] != '*' && arr[X][Y] != 'X' && visited[X][Y] == 0) {
						visited[X][Y] = visited[x][y] + 1;
						q.push(make_pair(X, Y));
						
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
		cin >> arr[i][j];
		if (arr[i][j] == 'S') {
			go_x = i; go_y = j; arr[i][j] = '.';
		}
		if (arr[i][j] == 'D') {
			gool_x = i; gool_y = j;
		}
		if (arr[i][j] == '*') river.push(make_pair(i, j));
	}

	int result = BFS(go_x, go_y);
	if (result == -1) printf("KAKTUS");
	else printf("%d", result);

	return 0;
}
