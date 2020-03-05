#include<stdio.h>

/*
주사위를 굴릴 때, 동서남북방향이 바뀌는 것을 memory로 저장

** 행렬의 좌표와, 주사위판의 좌표를 혼동하면 안됨! **
   남쪽으로 이동 : x좌표 + 1
   동쪽으로 이동 : y좌표 + 1
*/

int arr[21][21] = { 0 };//지도배열
int N, M, nowx, nowy, dir;
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { 1, -1, 0, 0 };
int dice[6] = { 0 };//주사위 배열
int memory[6] = { 1, 2, 4, 3, 0, 5 }; //[북 동 남 서 윗 밑] - dice의 인덱스
int copy_memory[6];
bool isValid(int x, int y) {//범위 안에 존재하는가?
	return x >= 0 && x < N && y >= 0 && y < M;
}

void move() {
	if (dir == 1) { //동쪽
		copy_memory[0] = memory[0]; copy_memory[2] = memory[2];
		copy_memory[5] = memory[1]; copy_memory[4] = memory[3];
		copy_memory[1] = memory[4]; copy_memory[3] = memory[5];
		for (int i = 0; i < 6; i++) memory[i] = copy_memory[i];
	}
	else if (dir == 2) { //서쪽
		copy_memory[0] = memory[0]; copy_memory[2] = memory[2];
		copy_memory[1] = memory[5]; copy_memory[3] = memory[4];
		copy_memory[4] = memory[1]; copy_memory[5] = memory[3];
		for (int i = 0; i < 6; i++) memory[i] = copy_memory[i];
	}
	else if (dir == 3) { //남쪽
		copy_memory[1] = memory[1]; copy_memory[3] = memory[3];
		copy_memory[2] = memory[4]; copy_memory[5] = memory[2];
		copy_memory[0] = memory[5]; copy_memory[4] = memory[0];
		for (int i = 0; i < 6; i++) memory[i] = copy_memory[i];
	}
	else if (dir == 4) { //북쪽
		copy_memory[1] = memory[1]; copy_memory[3] = memory[3];
		copy_memory[4] = memory[2]; copy_memory[2] = memory[5];
		copy_memory[5] = memory[0]; copy_memory[0] = memory[4];
		for (int i = 0; i < 6; i++) memory[i] = copy_memory[i];
	}
}

int main() {
	int T;
	scanf("%d %d %d %d %d", &N, &M, &nowx, &nowy, &T);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &arr[i][j]);

	while (T--) {
		scanf("%d", &dir);
		int X = nowx + dx[dir - 1], Y = nowy + dy[dir - 1];
		if (isValid(X, Y)) {
			nowx = X; nowy = Y;
			move();//다이스 이동
			if (arr[nowx][nowy] == 0) {
				arr[nowx][nowy] = dice[memory[5]];
			}
			else {
				dice[memory[5]] = arr[nowx][nowy];
				arr[nowx][nowy] = 0;
			}
			printf("%d\n", dice[memory[4]]);
		}
	}
	return 0;
}