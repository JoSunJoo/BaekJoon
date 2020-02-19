#include<stdio.h>

int main() {
	int n;	scanf("%d", &n);
	int res = 0;
	for (int i = 0; i < 5; i++) {
		int temp;	scanf("%d", &temp);
		if (n == temp) res++;
	}
	printf("%d", res);
	return 0;
}
