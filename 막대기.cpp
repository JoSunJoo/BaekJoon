#include<stdio.h>

int main() {
	double N;	 scanf("%lf", &N);
	double x=0, stick = 64;
	int cnt = 0;

	if (N == 64) {
		printf("1");
		return 0;
	}
	while (1) {
		if (x == N) break;
		stick = stick / 2;
		if (stick + x <= N) {
			x += stick;
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
