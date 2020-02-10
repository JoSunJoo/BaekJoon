#include<stdio.h>

int main() {
	int N, K;
	while (scanf("%d %d", &N, &K) != EOF) {
		unsigned long long result = N;
		unsigned long long stamp = N;
		while (stamp / K != 0) {
			result += stamp / K;
			stamp = stamp / K + stamp % K;
		}
		printf("%u\n", result);
	}
	return 0;
}
