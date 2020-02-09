#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;

int main() {
	int T;	scanf("%d", &T);

	while (T--) {
		int N;	 scanf("%d", &N);
		pair<int, int> arr[100001];
		for (int i = 0; i < N; i++) scanf("%d %d", &arr[i].first, &arr[i].second);

		sort(arr, arr+N);
		int cnt = 1;
		int point = arr[0].second;
		for (int i = 1; i < N; i++) {
			if (arr[i].second < point) {
				cnt++;
				point = arr[i].second;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
