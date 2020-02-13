#include<stdio.h>
#include<algorithm>
using namespace std;

int multi(int n, int a) {
	int temp = 1;
	for (int i = 1; i <= a; i++)
		temp *= n;
	return temp;
}

int main() {
	int a, b;	 scanf("%d %d", &a, &b);
	int arr1[10000] = { 0 }, arr2[10000] = { 0 };

	for (int i = 2; i <= a; i++) {
		if (a%i == 0) {
			arr1[i]++;
			a /= i;	i--;
		}
	}

	for (int i = 2; i <= b; i++) {
		if (b%i == 0) {
			arr2[i]++;
			b /= i;	i--;
		}
	}

	int mini = 1, maxi = 1;
	for (int i = 0; i < 10000; i++) {
		if (arr1[i] == 0 && arr2[i] == 0) continue;
		mini *= multi(i, min(arr1[i], arr2[i]));
		maxi *= multi(i, max(arr1[i], arr2[i]));
	}
	printf("%d\n%d", mini, maxi);
	return 0;
}
