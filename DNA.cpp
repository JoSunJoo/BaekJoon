#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int N, M;
string arr[1001];
char check(int idx){//각 string에서 해당 index 중 가장 중복이 많이 되는 문자 반환
	int cnt[30] = {0};
	int maxi = 0;
	for (int i = 0; i < N; i++) {
		cnt[arr[i][idx] - 'A']++; //해당 문자의 아스키코드 - 'A' => 0~26으로 바뀜
		maxi = max(maxi, cnt[arr[i][idx]-'A']);//최대값 갱신
	}

	for (int i = 0; i < 30; i++)//최대값이 같을 경우, 사전순으로 반환
		if (cnt[i] == maxi) return 'A' + i;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	char result[55];//결과값 string
	for (int i = 0; i < M; i++) {
		result[i] = check(i);
		printf("%c", result[i]);
	}
	int hd = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr[i][j] != result[j]) hd++;

	printf("\n%d", hd);

	return 0;
}
