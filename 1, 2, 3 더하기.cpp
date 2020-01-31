#include<stdio.h>
#include<algorithm>
using namespace std;

int dp[15] = {1, 1, 2, 4, 0};

int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		int N;	scanf("%d", &N);
		for (int i = 4; i <= N; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		printf("%d\n", dp[N]);
	}
	return 0;
}
