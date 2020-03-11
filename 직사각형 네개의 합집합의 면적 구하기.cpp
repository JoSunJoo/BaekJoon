#include<stdio.h>

int arr[102][102] = { 0 };
int main() {
	for (int t = 0; t < 4; t++) {
		int x1, y1, x2, y2;	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = x1; i < x2; i++) 	for (int j = y1; j < y2; j++)
				arr[i][j] = 1;
	}

	int res = 0;
	for (int i = 0; i < 101; i++) for (int j = 0; j < 101; j++)
		if (arr[i][j] == 1) res++;

	printf("%d", res);
	return 0;
}