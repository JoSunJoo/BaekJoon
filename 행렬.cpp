#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int N, M;
int arr1[51][51], arr2[51][51];
int cnt = 0;
void change(int x, int y) {
	cnt++;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr1[i + x][j + y] = !arr1[i + x][j + y];
		}
	}
}

bool same() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr1[i][j] != arr2[i][j])
				return false;

	return true;
}

int main() {
	scanf("%d %d", &N, &M);
	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) arr1[i][j] = str.at(j) - '0';
	}
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) arr2[i][j] = str.at(j) - '0';
	}

	if (!same() && (N < 3 || M < 3)) {
		printf("-1");
		return 0;
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (arr1[i][j] != arr2[i][j])
				change(i, j);
		}
	}

	if (!same())
		cnt = -1;

	printf("%d", cnt);
	return 0;
}
