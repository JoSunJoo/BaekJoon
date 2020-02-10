#include<stdio.h>
unsigned long long dp[10][1001];
int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		int N;	scanf("%d", &N);
		for (int i = 0; i < 10; i++) dp[i][0] = 1;
		for (int i = 1; i < N; i++) {
			dp[0][i] = (dp[7][i - 1])%1234567;
			dp[1][i] = (dp[4][i - 1] + dp[2][i - 1]) % 1234567;
			dp[2][i] = (dp[1][i - 1] + dp[3][i - 1] + dp[5][i - 1]) % 1234567;
			dp[3][i] = (dp[2][i - 1] + dp[6][i - 1]) % 1234567;
			dp[4][i] = (dp[1][i - 1] + dp[5][i - 1] + dp[7][i - 1]) % 1234567;
			dp[5][i] = (dp[2][i - 1] + dp[4][i - 1] + dp[6][i - 1] + dp[8][i - 1]) % 1234567;
			dp[6][i] = (dp[3][i - 1] + dp[5][i - 1] + dp[9][i - 1]) % 1234567;
			dp[7][i] = (dp[4][i - 1] + dp[8][i - 1] + dp[0][i - 1]) % 1234567;
			dp[8][i] = (dp[5][i - 1] + dp[7][i - 1] + dp[9][i - 1]) % 1234567;
			dp[9][i] = (dp[8][i - 1] + dp[6][i - 1]) % 1234567;
		}
		unsigned long long res = 0;
		for (int i = 0; i < 10; i++) res = (res + dp[i][N - 1]) % 1234567;
		printf("%u\n", res);
	}
	return 0;
}
