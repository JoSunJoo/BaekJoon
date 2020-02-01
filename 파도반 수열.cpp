#include<stdio.h>
unsigned long long arr[102] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 0};

int main() {
	for (int i = 7; i <= 100; i++)
		arr[i] = arr[i - 1] + arr[i - 5];

	int T;	scanf("%d", &T);
	while (T--) {
		int n;	scanf("%d", &n);
		printf("%llu\n", arr[n]);
	}

	return 0;
}
