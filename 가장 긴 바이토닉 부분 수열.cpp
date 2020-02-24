#include<stdio.h>
#include<algorithm>
using namespace std;

/*
LIS 알고리즘 (최장 증가 부분수열)
dp[i] = i번째 원소를 마지막으로 하는 LIS의 길이

바이토닉 수열 = 최장 증가 부분수열 + 최장 감소 부분수열(n-1부터 거꾸로 구하기) - 1
*/

int main() {
	int N;	scanf("%d", &N);
	int arr[1001];
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	int dp[2][1001] = { 0 }; //0:왼->오 방향의 LIS  1:오->왼 방향의 LIS

	for (int i = 0; i < N; i++) { //왼->오 방향의 LIS
		dp[0][i] = 1;
		int now = 0;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j])
				now = max(now, dp[0][j]);
		dp[0][i] = now + 1;
	}

	for (int i = N - 1; i >= 0; i--) { //오->왼 방향의 LIS
		dp[1][i] = 1;
		int now = 0;
		for (int j = N - 1; j > i; j--)
			if (arr[i] > arr[j])
				now = max(now, dp[1][j]);
		dp[1][i] = now + 1;
	}

	int res = 0;
	for (int i = 0; i < N; i++)
		res = max(res, dp[0][i]+dp[1][i]);
	printf("%d", res-1);//가운데 수가 중복이므로 -1 해주기!

	return 0;
}
