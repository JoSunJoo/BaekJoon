#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int N, M;	scanf("%d %d", &N, &M);
	int pac=10000, one=10000;
	int result = 0;
	for (int i = 0; i < M; i++) {
		int a, b;	 scanf("%d %d", &a, &b);
		pac = min(a, pac);	 one = min(b, one);
	}
	if (one * 6 < pac)
		result = one * N;
	else {
		int temp = N / 6; int temp2 = N % 6;
		if (pac < temp2*one)
			result = (temp + 1) * pac;
		else
			result = temp * pac + temp2 * one;
	}
	printf("%d", result);
	return 0;
}
