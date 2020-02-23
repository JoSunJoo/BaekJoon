#include<stdio.h>

int main() {
	int N;	scanf("%d", &N);
	for (int i = 1; i < N; i++) printf(" ");
	printf("*\n");
	for (int i = 1; i < N; i++) {
		for (int j = N-1; j >i; j--) printf(" ");
		printf("*");
		for (int j = 2*i-1; j >= 1; j--) printf(" ");
		printf("*\n");
	}

	return 0;
}
