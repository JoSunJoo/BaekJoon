#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int N, K, cnt=0;
int arr[101];
vector<int> multitab;

int search(int n, int p) {
	for (int i = p; i < K; i++) {
		if (arr[i] == n) return i;
	}
	return 105;
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) scanf("%d", &arr[i]);

	for (int a = 0; a < K; a++) {
		bool flag = false;
		for (int i = 0; i < multitab.size(); i++) {
			if (multitab[i] == arr[a]) {
				flag = true; break;
			}
		}
		if (flag) continue;
		if (multitab.size() < N) {
			multitab.push_back(arr[a]);
		}
		else {
			vector<int> schedule;
			for (int i = 0; i < multitab.size(); i++) {
				int temp = 105;
				for (int j = a+1; j < K; j++)
					temp = min(temp, search(multitab[i], j));
				schedule.push_back(temp);
			}

			int val = schedule[0], point=0;
			for (int i = 0; i < schedule.size(); i++) {
				if (val < schedule[i]) {
					point = i;
					val = schedule[i];
				}
			}
			multitab[point] = arr[a];
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}
