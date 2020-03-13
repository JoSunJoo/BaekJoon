#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

/*
등수의 범위가 500000까지이므로 오차를 다 더했을때
int의 범위를 벗어나는 것이 포인트인 문제이다!

백준에서는 보통 long long으로 풉시다...
*/

int main() {
	int N;	scanf("%d", &N);
	int arr[500002] = { 0 };

	for (int i = 0; i < N; i++) {
		int temp;	scanf("%d", &temp);
		arr[i] = temp - 1;
	}
	sort(arr, arr + N);//예측 등수 정렬
	long long res = 0;
	for (int i = 0; i < N; i++) {//예측등수와 현재 정렬된 등수의 차를 더함
		res += abs(i - arr[i]);
	}
	cout << res;
	return 0;
}
