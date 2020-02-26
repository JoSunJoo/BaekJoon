#include<stdio.h>
#include<iostream>
using namespace std;

/*
같은 수에 대하여 다른 구간의 합을 구하는 문제!
1. dp를 활용하여 처음부터 해당 구간까지의 합을 구하기
2. 구간을 입력받으면 구간의 시작과 끝의 dp차이를 구하여 답 구하기
*/

int main() {
	int N, M;	scanf("%d %d", &N, &M);
	unsigned long long arr[100002] = {0};
	for (int i = 1; i <= N; i++) {
		int temp;	scanf("%d", &temp);
		arr[i] = arr[i - 1] + temp;
	}
	while (M--) {
		int a, b;	scanf("%d %d", &a, &b);
		unsigned long long res = 0;
		res = arr[b] - arr[a - 1];
		cout << res << '\n';
	}
	return 0;
}
