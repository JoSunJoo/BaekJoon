#include<stdio.h>
#include<math.h>
int N;
int chess[15] = { 0 };
int cnt = 0;
bool check(int index, int data) {
	for (int i = 0; i < index; i++) {
		if (chess[i] == data) return false;
		if (abs(chess[i] - chess[index]) == abs(i - index)) return false;
	}
	return true;
}

void DFS(int len) {
	if (len == N) {
		cnt++; return;
	}

	for (int i = 0; i < N; i++) {
		chess[len] = i;
		if (check(len, i)) DFS(len + 1);
	}
}

int main() {
	scanf("%d", &N);

	DFS(0);
	printf("%d", cnt);

	return 0;
}
