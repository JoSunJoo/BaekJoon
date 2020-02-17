#include<stdio.h>

int main() {
	int arr[11] = { 0 };
	int N;	 scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;	scanf("%d", &temp);
		for (int j = 0; j < N; j++) {
			if (arr[j] == 0 && temp == 0) {
				arr[j] = i + 1;
				break;
			}
			else if (arr[j] == 0 && temp > 0)
				temp--;
		}
	}
	for (int i = 0; i < N; i++) printf("%d ", arr[i]);
	return 0;
}
