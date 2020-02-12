#include<stdio.h>
#include<algorithm>
using namespace std;

int result[14];
int arr[14];
int N;
int visited[14] = { 0 };

void DFS(int p, int len) {
	if (len == 6) {
		for (int i = 0; i < len; i++) printf("%d ", result[i]);
		printf("\n");
	}

	for (int i = p; i < N; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			result[len] = arr[i];
			DFS(i, len + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			visited[i] = 0;
		}
		sort(arr, arr+N);
		DFS(0, 0);
		printf("\n");
	}
	return 0;
}
