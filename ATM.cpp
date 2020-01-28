#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int N; scanf("%d", &N);
	int arr[1005];
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	sort(arr, arr + N);
	int res = arr[0];

	for (int i = 1; i < N; i++) {
		arr[i] = arr[i] + arr[i - 1];
		res += arr[i];
	}
	printf("%d", res);
	return 0;
}
