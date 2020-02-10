#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int arr[2000002];
int f=-1, b=-1;
int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		char str[10];
		scanf("%s", str);
		if (str[1] == 'u') {
			int temp;	 scanf("%d", &temp);
			b++;
			arr[b] = temp;
		}
		else if (str[1] == 'r') {
			if (f==b) printf("-1\n");
			else
				printf("%d\n", arr[f+1]);
		}
		else if (str[1] == 'a') {
			if (f == b) printf("-1\n");
			else printf("%d\n", arr[b]);
		}
		else if (str[1] == 'o') {
			if (f==b) printf("-1\n");
			else {
				f++;
				printf("%d\n", arr[f]);
			}
		}
		else if (str[1] == 'i') {
			printf("%d\n", b-f);
		}
		else if (str[1] == 'm') {
			if (f==b) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}
