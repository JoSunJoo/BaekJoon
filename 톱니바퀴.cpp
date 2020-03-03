#include<stdio.h>
#include<string>
#include<iostream>
#include<utility>
using namespace std;

/*
이 문제는 톱니바퀴의 회전을 구현하는 문제이다.
일일히 회전마다 모든 수를 바꾸는 것이 아니라, 맞다은 부분의 인덱스 값을 변화시킴으로서
회전을 대체하는 방식으로 구현하였다.
*/

string topni[4];//톱니바퀴 배열
int turn[4] = { 0, 0, 0, 0 };//톱니바퀴의 회전 여부 기록(-1:시계방향 회전 / 1:반시계방향 회전)
int point[4][2] = { {2, 6}, {2, 6}, {2, 6}, {2, 6} };//톱니바퀴의 맞다은 부분을 저장함
int T;

void doit() {
	for (int i = 0; i < 4; i++) {
		if (turn[i] < 0) { //시계방향으로 회전
			point[i][0] = (point[i][0] + 1) % 8;
			point[i][1] = (point[i][1] + 1) % 8;
		}
		else if (turn[i] > 0) { //반시계방향으로 회전
			point[i][0] = (point[i][0] + 7) % 8;
			point[i][1] = (point[i][1] + 7) % 8;
		}
	}
}

int main() {
	cin >> topni[0] >> topni[1] >> topni[2] >> topni[3];
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i < 4; i++) turn[i] = 0;//회전여부 초기화
		int num, dir;	scanf("%d %d", &num, &dir);
		num--;
		turn[num] = dir;//현재 톱니바퀴의 회전 저장

		int temp = num - 1;
		while (temp >= 0) {//현재를 기준으로 왼쪽을 체크
			if (topni[temp][point[temp][0]] != topni[temp + 1][point[temp + 1][1]])//맞다은 부분이 다르면?
				turn[temp] = -1 * turn[temp+1];//기존과 반대로 회전!
			else break;//맞다은 부분이 같으면 회전 중지
			temp--;
		}

		temp = num + 1;
		while (temp < 4) {//현재를 기준으로 오른쪽을 체크
			if (topni[temp][point[temp][1]] != topni[temp - 1][point[temp - 1][0]])//맞다은 부분이 다르면?
				turn[temp] = -1 * turn[temp-1];//기존과 반대로 회전!
			else break;//맞다은 부분이 같으면 회전 중지
			temp++;
		}

		doit();//회전 적용

	}
	int res = 0, mul = 1;
	for (int i = 0; i < 4; i++) {//회전 결과에 따른 점수 계산
		res += (topni[i][(point[i][1]+2)%8]-'0') * mul;
		mul = mul * 2;
	}
	printf("%d", res);
	return 0;
}
