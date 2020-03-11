#include<stdio.h>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

/*
이 문제는 사이클이 도는 배열의 집합을 출력하는 문제이다.
처음에는 완전탐색을 사용하여 각 케이스별로 전부 탐색을 시도하였지만 
결과는 시간초과...

인덱스의 값과 배열의 값이 일치한다는 말은
깊이탐색을 한 결과가 처음 시작한 위치의 인덱스와 같다는 것을 의미한다!
*/

int N, arr[101], cnt=0;
int visited[101] = { 0 }, cycle[101] = { 0 };

bool DFS(int point, int data) { //시작위치의 인덱스, 현재의 데이터
	if (visited[data] == 1) return false;
	visited[data] = 1;

	if (point == data || DFS(point, arr[data])) {//인덱스와 데이터가 같거나, 사이클이 성공하는 경우
		cycle[data] = 1;
		cnt++;
		return true;
	}
	return false;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;	scanf("%d", &temp);
		arr[i] = temp - 1;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) visited[j] = cycle[j]; //사이클이 돈 곳은 더이상의 방문은 생략
		DFS(i, arr[i]);
	}

	printf("%d\n", cnt);
	for (int i = 0; i < N; i++) 
		if(cycle[i] != 0) printf("%d\n", i+1);

	return 0;
}