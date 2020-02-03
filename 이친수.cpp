#include<stdio.h>

int main() {
	int N; scanf("%d", &N);
	unsigned long long dp[2][100];
	dp[0][1] = 0;	dp[1][1] = 1;
	dp[0][2] = 1; dp[1][2] = 0;
	dp[0][3] = 1; dp[1][3] = 1;
	for (int i = 4; i <= N; i++) {
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
		dp[1][i] = dp[0][i - 1];
	}
	printf("%lld", dp[0][N] + dp[1][N]);
	return 0;
}
