#include<stdio.h>

int main() {
	int N;	scanf("%d", &N);
	for (int i = 1; i <= N; i++) printf("*");
	for (int i = 1; i <= 2 * N - 3; i++) printf(" ");
	for (int i = 1; i <= N; i++) printf("*");
	printf("\n");

	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= i; j++) printf(" ");
		printf("*");
		for (int j = 1; j <= N - 2; j++) printf(" ");
		printf("*");
		for (int j = 1; j < 2*(N - i-1); j++) printf(" ");
		printf("*");
		for (int j = 1; j <= N - 2; j++) printf(" ");
		printf("*\n");
	}

	for (int i = 1; i < N; i++) printf(" ");
	printf("*");
	for (int j = 1; j <= N - 2; j++) printf(" ");
	printf("*");
	for (int j = 1; j <= N - 2; j++) printf(" ");
	printf("*\n");

	for (int i = N-2; i >=1; i--) {
		for (int j = 1; j <= i; j++) printf(" ");
		printf("*");
		for (int j = 1; j <= N - 2; j++) printf(" ");
		printf("*");
		for (int j = 1; j < 2 * (N - i - 1); j++) printf(" ");
		printf("*");
		for (int j = 1; j <= N - 2; j++) printf(" ");
		printf("*\n");
	}

	for (int i = 1; i <= N; i++) printf("*");
	for (int i = 1; i <= 2 * N - 3; i++) printf(" ");
	for (int i = 1; i <= N; i++) printf("*");

	return 0;
}
