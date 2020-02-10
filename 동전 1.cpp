#include<stdio.h>
#include<vector>
using namespace std;
int N, K;
int dp[10001];
vector<int> vec;
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int temp; scanf("%d", &temp);
		vec.push_back(temp);
	}

	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = vec[i]; j <= K; j++)
			dp[j] += dp[j - vec[i]];
	}
	printf("%d", dp[K]);
	return 0;
}
