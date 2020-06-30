#include<stdio.h>
int n;
void printOdd() {
	if (n % 2 == 0) {
		for (int i = 0; i < n / 2-1; i++)
			printf("* ");
		printf("*\n");
	}
	else {
		for (int i = 0; i < n / 2; i++)
			printf("* ");
		printf("*\n");
	}
}

void printEven() {
	for (int i = 0; i < n / 2; i++)
		printf(" *");
	printf("\n");
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printOdd();
		printEven();
	}
	return 0;
}
