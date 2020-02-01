#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int N;	scanf("%d", &N);
	int dp[1003][3] = { 0 }, map[1003][3] = { 0 };

	for (int i = 1; i <= N; i++)
		scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
	dp[1][0] = map[1][0];
	dp[1][1] = map[1][1];
	dp[1][2] = map[1][2];
	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + map[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + map[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + map[i][2];
	}

	int res = min(dp[N][0], min(dp[N][1], dp[N][2]));
	printf("%d", res);
	return 0;
}
