#include<stdio.h>

int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		int N;	scanf("%d", &N);
		int dp[4][10002] = {0};
		dp[1][1] = 1;   dp[2][1] = 0; dp[3][1] = 0;
		dp[1][2] = 1;	dp[2][2] = 1; dp[3][2] = 0;
		dp[1][3] = 1;	dp[2][3] = 1;	dp[3][3] = 1;
		for (int i = 4; i <= N; i++) {
			dp[1][i] = dp[1][i - 1];
			dp[2][i] = dp[1][i - 2] + dp[2][i - 2];
			dp[3][i] = dp[1][i - 3] + dp[2][i - 3] + dp[3][i - 3];
		}
		printf("%d\n", dp[1][N] + dp[2][N] + dp[3][N]);
	}
	return 0;
}
