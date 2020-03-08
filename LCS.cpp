#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

/*
이 문제는 LCS(Longest Commeon Subsequence)문제이다.
문제의 해법은 다음과 같다.
1. 2차원 배열의 dp를 정의한다
2. 문자열을 차례로 비교한다
   2-1 문자열이 같은 경우
       현재 위치의 값(dp[i][j]) = 왼쪽 대각선 값 +1(dp[i-1][j-1] + 1)
   2-2 문자열이 다른 경우
	   현재 위치의 값(dp[i][j]) = max(왼쪽값, 위쪽 값) (max(dp[i-1][j], dp[i][j-1]))
*/

int dp[1002][1002] = { 0 };
int main() {
	string a, b;
	cin >> a >> b;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	printf("%d", dp[a.length()][b.length()]);
	return 0;
}