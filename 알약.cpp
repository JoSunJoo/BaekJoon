#include<stdio.h>
#include<iostream>
using namespace std;

/*
메모이제이션 사용하기!(시간초과 주의)
w = 한 알 / h = 반 알
한 알을 먹을 경우 -> w-1 && h+1
반 알을 먹을 경우 -> w && h-1
*/

int N;
long long dp[31][31] = {0};
long long solve(int w, int h) {
	if (w < 0 || h < 0) return 0;
	if (w == 0 && h==0) return 1;
	if (dp[w][h] > 0) return dp[w][h];

	dp[w][h] = solve(w - 1, h + 1) + solve(w, h - 1);
	return dp[w][h];
}

int main() {
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;
		cout << solve(N, 0) << '\n';
	}
	return 0;
}
