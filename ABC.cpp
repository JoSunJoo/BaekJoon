#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int arr[3];
	for (int i = 0; i < 3; i++) scanf("%d", &arr[i]);
	sort(arr, arr+3);

	char str[4];	scanf("%s", str);
	for (int i = 0; i < 3; i++) {
		if (str[i] == 'A') printf("%d ", arr[0]);
		else if (str[i] == 'B') printf("%d ", arr[1]);
		else printf("%d ", arr[2]);
	}

	return 0;
}
