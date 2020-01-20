#include<stdio.h>

int N;
int arr[20][20];
int visited[20] = { 0 };
int result = 1000000;

int cal(int index) {
	int res = 0;
	if (visited[index] == 0) {
		for (int i = 0; i < N; i++) {
			if (visited[i] == 0 && i != index) {
				res += arr[index][i];
			}
		}
		return res;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visited[i] == 1 && i != index) {
				res += arr[index][i];
			}
		}
		return -1*res;
	}
}

void func(int len, int p) {
	if (len == N/2) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			temp += cal(i);
		}
		if (temp < 0) temp *= -1;
		result = (result > temp) ? temp : result;

		return;
	}

	for (int i = p; i < N; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			func(len+1, i);
			visited[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	func(0, 0);
	printf("%d", result);
	return 0;
}
