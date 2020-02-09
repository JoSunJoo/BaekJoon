#include<stdio.h>

int main() {
	int N;	 scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		if (i % 2 == 1) printf(" ");
		for (int j = 0; j < N; j++)
			printf("* ");
		printf("\n");
	}


	return 0;
}
