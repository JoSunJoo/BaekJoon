#include<stdio.h>

/*
해당 문제는 dp를 활용한 문제이다.
1. 짝수일 때에만 타일을 채울 수 있다.
2. 짝수 별로 +2의 예외가 발생한다.
3. 기존의 값을 만들 때 전 값 * dp[2]를 한다
	=> 전값의 오른쪽에 2짜리 타일을 붙임
	=> 각 타일의 예외값에는 왼쪽에 2짜리를 붙여야 함

	따라서, 점화식
	dp[n] = dp[n-2]*dp[2] + (dp[2 ... n-4] * 2) + 2
*/

int main() {
	int N;	scanf("%d", &N);
	int dp[32] = { 0, 0, 3 };

	for (int i = 4; i <= N; i+=2) {
		dp[i] = dp[i - 2] * dp[2];
		for (int j = 2; j<=i-4; j += 2)
			dp[i] += dp[j] * 2;

		dp[i] += 2;
	}

	printf("%d", dp[N]);

	return 0;
}
