#include<stdio.h>

int main() {
	int N;	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {//오름차순 정렬
		for (int j = 1; j <= i; j++) printf("*");
		printf("\n");
	}

	for (int i = N - 1; i >= 1; i--) { //내림차순 정렬
		for (int j = N - i; j < N; j++) printf("*");
		printf("\n");
	}
	return 0;
}
