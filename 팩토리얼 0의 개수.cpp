#include<stdio.h>
/*
이 문제는 N!에서 뒷자리가 0인 수의 개수를 구하는 문제이다.
수의 특성 상, 5의 약수 개수가 2의 약수 개수보다 작을 것이므로!!
5의 약수의 개수만 구하여 답을 출력한다.
*/
int res=0, N;
int main() {
	scanf("%d", &N);
	if (N < 5) {
		printf("0"); return 0;
	}
	while (N > 0) {
		N /= 5;
		res += N;
	}

	printf("%d", res);
	return 0;
}