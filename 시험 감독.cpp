#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int N, B, C;
int A[1000001];
unsigned long long res = 0;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	scanf("%d %d", &B, &C);

	for (int i = 0; i < N; i++) {
		A[i] -= B; res++;
		if (A[i] > 0) {
			if (A[i] % C == 0) res += (A[i] / C);
			else res += (A[i] / C) + 1;
		}
	}

	cout << res;
	return 0;
}