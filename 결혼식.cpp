#include<stdio.h>
#include<vector>
using namespace std;

int N, M;
int clsrn[501] = { 0 };//clsrn : 친구
int arr[501][501] = { 0 };
vector<int> lists;

void check(int num) {//친구의 친구 체크하기
	for (int i = 2; i <= N; i++)
		if (arr[num][i] == 1) 	clsrn[i] = 1;
}

int main() {
	scanf("%d", &N); scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int a, b;	scanf("%d %d", &a, &b);
		arr[a][b] = 1; arr[b][a] = 1;//친구를 배열을 사용한 그래프로 나타내기
	}

	for (int i = 2; i <= N; i++) {//1번의 친구 list만들기
		if (arr[1][i] == 1) {
			clsrn[i] = 1;
			lists.push_back(i);
		}
	}

	//친구의 친구 체크하기
	for (int i = 0; i < lists.size(); i++) check(lists[i]);

	int res = 0;
	for (int i = 1; i <= N; i++)
		if (clsrn[i] == 1) res++;

	printf("%d", res);
	return 0;
}
