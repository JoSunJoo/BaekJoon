#include<stdio.h>
#include<algorithm>
using namespace std;

/*
이 문제는 국어능력이 필요한 문제였다..
 한 좌표를 커버하기 위해서는 왼쪽, 오른쪽으로 0.5의 간격이 필요하다
   == 한 좌표를 커버하기 위해 1의 값이 필요하다

이 말을 잘못 해석해서 한참 삽질한 문제이다...(문제좀 잘읽자!)

알고리즘 
1. 커버가 필요한 좌표를 정렬한다
2-1. 현재좌표와 직전 좌표의 거리차 <= 테이프의 길이
   => 하나의 테이프로 커버하기!
2-2. 현재좌표와 직전 좌표의 거리차 > 테이프의 길이
   => 테이프 추가하기!
*/

int N, L;
int arr[1002];
int main() {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	sort(arr, arr + N);
	int result = 1, len = L-1;
	int needs = 0;
	for (int i = 1; i < N; i++) {
		needs = arr[i]-arr[i-1];
		if (len >= needs) len -= needs;
		else {
			len = L-1; result++;
		}
	}
	printf("%d", result);
	return 0;
}