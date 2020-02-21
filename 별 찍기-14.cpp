#include<stdio.h>

/*
이 문제는 입력을 받은 수 만큼
ㅁ모양으로 출력하는 문제이다
*/

int main() {
	int N;	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for(int i=1; i<=N; i++)	printf("*");
		printf("\n");
	}
	return 0;
}
