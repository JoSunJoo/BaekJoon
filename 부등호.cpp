#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int N;
vector<char> vec; //부등호
vector<int> arr; //데이터
string mini, maxi;

/*
prev_permutation : 4321 -> 1234로 순서대로 조합을 만듬
next_permutation : 1234 -> 4321로 순서대로 조합을 만듬
	=> 조합이 끝나면 false를 반환함
*/

bool isOk() { //부등호가 성립하는 조합인가?
	for (int i = 0; i < N; i++) {
		if (vec[i] == '<' && arr[i] > arr[i + 1]) return false;
		if (vec[i] == '>' && arr[i] < arr[i + 1]) return false;
	}
	return true;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char temp;	cin >> temp;
		vec.push_back(temp);
	}

	//최대
	for (int i = 0; i <= N; i++) arr.push_back(9-i);

	while (!isOk()) prev_permutation(arr.begin(), arr.end());
	for (int i = 0; i <= N; i++) printf("%d", arr[i]);
	printf("\n");

	//최소
	for (int i = 0; i <= N; i++) arr[i] = i;

	while (!isOk()) next_permutation(arr.begin(), arr.end());
	for (int i = 0; i <= N; i++) printf("%d", arr[i]);
	return 0;
}
