#include<stdio.h>
#include<algorithm>
using namespace std;

int dp[1002] = {0};
int arr[1002] = {0};
int N;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 1002; i++) dp[i] = 1;
	int res = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		res = max(res, dp[i]);
	}
	printf("%d", res);

	return 0;
}
