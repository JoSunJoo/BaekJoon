#include<stdio.h>
int main() {
	int a[46] = { 1, 0, 1, 1, 2, 3, 5 }, b[46] = { 0, 1, 1, 2, 3, 5, 8};
	int N;	scanf("%d", &N);

	for (int i = 6; i <= N; i++) {
		a[i] = b[i - 1];
		b[i] = b[i - 1] + a[i - 1];
	}
	printf("%d %d", a[N], b[N]);
	return 0;
}
