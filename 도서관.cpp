#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
int N, M;

int search(int dir, vector<int> arr) {
	int result=0;
	if (dir < 0) { //case 1
		int now = 0;
		while (now < arr.size()) {
			result += (arr[now] * -1)*2;
			now += M;
		}
	}
	else if (dir > 0) {
		int now = 0;
		while (now < arr.size()) {
			result += arr[arr.size()-1-now] * 2;
			now += M;
		}
	}
	return result;
}

int main() {
	int arr[10002] = { 0 }, result = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	sort(arr, arr+N);

	vector<int> vec1, vec2;
	for (int i = 0; i < N; i++) {
		if (arr[i] < 0) vec1.push_back(arr[i]);
		else vec2.push_back(arr[i]);
	}
	result = search(-1, vec1) + search(1, vec2);
	result -= max(abs(arr[0]), abs(arr[N - 1]));
	printf("%d", result);
	return 0;
}