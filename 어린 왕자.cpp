#include<stdio.h>
#include<math.h>
#include<utility>
using namespace std;

int N;
int x_1, y_1, x_2, y_2;
int x, y, r;

bool isVaild(int vers) { //vers 1:(x1, y1) / 2:(x2, y2)
	int distance;
	if(vers == 1)
		distance = (x - x_1)*(x - x_1) + (y - y_1)*(y - y_1);
	else
		distance = (x - x_2)*(x - x_2) + (y - y_2)*(y - y_2);
	if (distance < r*r) return true;

	return false;
}

int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		int result = 0;
		scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);
		int s;	scanf("%d", &s); //원의 갯수
		for (int i = 0; i < s; i++) {
			scanf("%d %d %d", &x, &y, &r);
			if (isVaild(1) && !isVaild(2)) result++; //출발점이 원 내부에 있을 경우
			if (!isVaild(1) && isVaild(2)) result++; //도착점이 원 내부에 있을 경우
		}
		printf("%d\n", result);
	}

	return 0;
}
