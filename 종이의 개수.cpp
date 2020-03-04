#include<stdio.h>
//1780번

int N;
int arr[3000][3000];
int res1=0, res2=0, res3=0;

bool isRight(int x1, int y1, int size) {//모두 같은 값인가?
	int num = arr[x1][y1];
	for (int i = x1; i < x1+size; i++) {
		for (int j = y1; j < y1+size; j++) {
			if (arr[i][j] != num) return false;
		}
	}
	//같은 값이면 계산하기
	if (num == -1) res1++;
	else if (num == 0) res2++;
	else if (num == 1) res3++;
	return true;
}

void func(int x1, int y1, int size) {//재귀함수
	if (isRight(x1, y1, size)) return;
	size /= 3; //사각형의 크기를 줄이기
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			func(x1 + size * i, y1 + size*j, size);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &arr[i][j]);

	func(0, 0, N);
	printf("%d\n%d\n%d", res1, res2, res3);
	return 0;
}
