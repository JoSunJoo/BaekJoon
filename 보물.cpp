#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;

int main() {
	int N;	scanf("%d", &N);
	int arr1[51], arr2[51];
	for (int i = 0; i < N; i++) scanf("%d", &arr1[i]);
	for (int i = 0; i < N; i++) scanf("%d", &arr2[i]);
	sort(arr1, arr1+N); //오름차순 정렬
	sort(arr2, arr2+N, greater<int>()); //내림차순 정렬

	int result = 0;
	for (int i = 0; i < N; i++)
		result += arr1[i] * arr2[i];
	printf("%d", result);

	return 0;
}
