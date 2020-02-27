#include<stdio.h>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

/*
이 문제는 문제의 설명이 살짝 모호하여 헷갈릴 수 있다.
"힌트를 보면 모든 땅이 잠기지 않을 수 있다" 라고 명시되어 있는데
이는 비가 오지 않을 수도 있다는 것을 의미한다.

따라서, 기본적으로 안전영역의 최소값은 1로 설정하고 문제를 접근해야 한다!!
(이것때문에 한번 틀림ㅜㅜ)
*/

int N, result = 1;
int arr[101][101] = { 0 }, copy_arr[101][101];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
bool isValid(int x, int y) {//범위 내에 존재하는가?
	return x >= 0 && x < N && y >= 0 && y < N;
}

void copy() {//배열 복사
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		copy_arr[i][j] = arr[i][j];
}

void BFS(int x, int y) {//안전영역 1개를 구하는 BFS
	queue<pair<int, int>> q;
	copy_arr[x][y] = 0;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int a = q.front().first, b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int X = a + dx[i], Y = b + dy[i];
			if (isValid(X, Y) && copy_arr[X][Y] != 0) {
				copy_arr[X][Y] = 0;
				q.push(make_pair(X, Y));
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	int maxi = 0;//모든 땅이 잠기는 강수량
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		scanf("%d", &arr[i][j]);
		maxi = max(maxi, arr[i][j]);
	}

	for (int t = 0; t <= maxi; t++) {//모든 땅이 잠길때까지!
		int cnt = 0;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			if(arr[i][j] > 0) arr[i][j]--;//전체 수를 -1해줌(전체 땅이 1칸씩 수위가 높아짐)
		}
		copy();//copy_arr에 데이터 복사
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {//안전 영역 구하기
			if (copy_arr[i][j] != 0) {
				BFS(i, j);
				cnt++;
			}
		}
		result = max(result, cnt);
	}
	printf("%d", result);
	return 0;
}
