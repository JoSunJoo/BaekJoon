#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;

int arr[9][9] = { 0 }, copy_arr[9][9] = {0};
pair<int, int> cctv[9];
int combi[9];//cctv의 방향 결정
int cnt = 0;//cctv 갯수
int N, M;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, -1, 0, 1 };
int result = 100;

void copy_array() { //배열 복사하기
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
		copy_arr[i][j] = arr[i][j];
}

bool isVaild(int x, int y) { //인덱스를 넘어가는가?
	return x >= 0 && x < N && y >= 0 && y < M;
}

void make_fill(int x, int y, int dir) { //cctv감시영역 체크
	x += dx[dir]; y += dy[dir];
	while (isVaild(x, y) && arr[x][y] != 6) {
		if (copy_arr[x][y] == 0) copy_arr[x][y] = -1;
		x += dx[dir]; y += dy[dir];
	}
}

void fill() {
	copy_array();//copy_arr에 데이터 복원
	for (int i = 0; i < cnt; i++) {
		int x = cctv[i].first, y = cctv[i].second;
		if (arr[x][y] == 1) {
			make_fill(x, y, combi[i]);
		}
		else if (arr[x][y] == 2) {
			make_fill(x, y, combi[i]);
			make_fill(x, y, (combi[i]+2)%4);
		}
		else if (arr[x][y] == 3) {
			make_fill(x, y, combi[i]);
			make_fill(x, y, (combi[i]+3)%4);
		}
		else if (arr[x][y] == 4) {
			make_fill(x, y, combi[i]);
			make_fill(x, y, (combi[i]+2)%4);
			make_fill(x, y, (combi[i]+3)%4);
		}
	}
	int temp = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (copy_arr[i][j] == 0) temp++;
	result = min(result, temp);
}

void make_combi(int count) {
	if (count == cnt) {
		fill();		return;
	}
	for (int i = 0; i < 4; i++) {
		combi[count] = i;
		make_combi(count + 1);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	pair<int, int> num5[9];
	int p = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		scanf("%d", &arr[i][j]);
		if (arr[i][j] > 0 && arr[i][j] < 5) {
			cctv[cnt].first = i; cctv[cnt].second = j;
			cnt++;
		}
		if (arr[i][j] == 5) {
			num5[p].first = i; num5[p].second = j;
			p++;
		}
	}

	int x, y;
	for (int i = 0; i < p; i++) {//cctv5일때 채워주기
		for (int j = 0; j < 4; j++) {
			x = num5[i].first; y = num5[i].second;
			x += dx[j]; y += dy[j];
			while (isVaild(x, y) && arr[x][y] != 6) {
				if (arr[x][y] == 0) arr[x][y] = -1;
				x += dx[j]; y += dy[j];
			}

		}
	}

	make_combi(0);
	printf("%d", result);

	return 0;
}
