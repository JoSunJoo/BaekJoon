#include<stdio.h>
#include<algorithm>
using namespace std;

int arr[101] = { 0 };

int gcd(int a, int b) {
	return a % b ? gcd(b, a%b) : b;
}

int main() {
	int N;	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	for (int i = 1; i < N; i++) {
		int maxi = gcd(max(arr[0], arr[i]), min(arr[i], arr[0]));
		printf("%d/%d\n", arr[0]/maxi, arr[i]/maxi);
	}
	return 0;
}
