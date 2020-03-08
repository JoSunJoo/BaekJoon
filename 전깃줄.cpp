#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int dp[501] = { 0 };
vector<pair<int, int>> vec;

bool cmp(pair<int, int> a, pair<int, int> b) {//vec.first를 오름차순으로 정렬
	return a.first < b.first;
}

int main() {
	int N;	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int t1, t2;	scanf("%d %d", &t1, &t2);
		vec.push_back(make_pair(t1, t2));
	}
	sort(vec.begin(), vec.end(), cmp);//입력값 정렬

	int res = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			//lis 적용
			if (dp[j] + 1 > dp[i] && vec[i].second > vec[j].second) dp[i] = dp[j] + 1;
		res = max(dp[i], res);
	}
	printf("%d", N-res);
	return 0;
}