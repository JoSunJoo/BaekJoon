#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
int dp[10002] = {0};
int arr[10002];
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
	dp[1] = arr[1];	dp[2] = arr[1] + arr[2];
 	for (int i = 3; i <= N; i++) {
		dp[i] = max(arr[i] + dp[i-2], dp[i-3]+arr[i]+arr[i-1]);
		dp[i] = max(dp[i], dp[i-1]);
	}

	printf("%d", dp[N]);
	return 0;
}
