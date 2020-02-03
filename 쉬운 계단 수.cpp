#include<stdio.h>
int dp[102][11];
int N;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < 10; i++) dp[1][i] = 1;

	for (int j = 2; j <= N; j++) {
		dp[j][0] = dp[j - 1][1];
		for (int i = 1; i < 9; i++)
			dp[j][i] = (dp[j-1][i - 1] + dp[j-1][i + 1])%1000000000;
		dp[j][9] = dp[j - 1][8];
	}
	int res = 0;
	for (int i = 1; i < 10; i++) {
		res = (res + dp[N][i])%1000000000;
	}
	printf("%d", res);
	return 0;
}
