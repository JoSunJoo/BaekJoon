#include<stdio.h>

/*
사용 알고리즘 : 모듈러 연산
주의점 : a^b는 수가 커질 수 있기 때문에 모듈러 연산을 통해
		수의 크기를 줄여줘야 한다!
(a*b)%m = (a%m)*(b%m)
*/

int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		int a, b;	scanf("%d %d", &a, &b);
		int num = a % 10;
		for (int i = 2; i <= b; i++) {
			num = (num*a) % 10;
		}
		if (num == 0) printf("10\n"); //나머지가 0이면 10이다!
		else printf("%d\n", num);
	}

	return 0;
}
