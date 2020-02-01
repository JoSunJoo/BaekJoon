#include<stdio.h>
#include<algorithm>
using namespace std;
int N, M; //입력갯수, cnt개수
int arr[10];
int res[10];
void DFS(int len, int p) {
	if (len == M) {
		for (int i = 0; i < len; i++) printf("%d ", res[i]);
		printf("\n");
		return;
	}
	int check[10001] = {0};
	for (int i = p; i < N; i++) {
		if (check[arr[i]] == 0) {
			check[arr[i]] = 1;
			res[len] = arr[i];
			DFS(len + 1, i);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	sort(arr, arr+N);
	DFS(0, 0);
	return 0;
}
