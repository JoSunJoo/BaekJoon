#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int N, M, K;	scanf("%d %d %d", &N, &M, &K);
	int result = 0;
	result = min(N / 2, M);
	N -= result * 2; M -= result;
	if (K > N + M) {
		int temp = K - N - M;
		result -= (temp / 3);
		if (temp % 3 != 0) result--;
	}
	printf("%d", result);
	return 0;
}
