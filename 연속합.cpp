#include<stdio.h>
#include<algorithm>
using namespace std;

int dp[100002];
int N;
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &dp[i]);

	int result = dp[0];

	for (int i = 1; i < N; i++) {
		result = max(result, dp[i]);
		if (dp[i] < dp[i] + dp[i - 1]) {
			dp[i] += dp[i - 1];
			result = max(result, dp[i]);
		}

	}

	printf("%d", result);
	return 0;
}
