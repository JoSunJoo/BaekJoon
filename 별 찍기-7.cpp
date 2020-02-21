#include<stdio.h>

int main() {
	int N;	scanf("%d", &N);
	for (int i = 0; i < N; i++) { //증가하는 별찍기
		for (int j = 0; j < N - i-1; j++) printf(" ");
		for (int j = 0; j < i*2+1 ; j++) printf("*");
		printf("\n");
	}

	for (int i = N-2; i >= 0; i--) { //감소하는 별찍기
		for (int j = 0; j < N-i-1; j++) printf(" ");
		for (int j = 0; j < 2*i+1; j++) printf("*");

		printf("\n");
	}
	return 0;
}
