#include<stdio.h>
#include<vector>
using namespace std;

int maxx = -1000000001, minx = 1000000001;
int num[12] = { 0 };
int N;
vector<int> oper; //연산자 배열 저장
int visited[12] = { 0 };
vector<int> vec;

void func(int len) {
	if (len == N - 1) {
		int res = num[0];
		for (int i = 0; i < N-1; i++) {
			if (vec[i] == 0) // 덧셈
				res += num[i + 1];
			else if (vec[i] == 1)// 뺄셈
				res -= num[i + 1];
			else if (vec[i] == 2)// 곱셈
				res *= num[i + 1];
			else if (vec[i] == 3) { // 나눗셈
				if (num[i + 1] == 0)  return;
				res /= num[i + 1];
			}
		}

		if (maxx < res) maxx = res;
		if (res < minx) minx = res;

		return;
	}

	for (int i = 0; i < N-1; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			vec.push_back(oper[i]);
			func(len + 1);
			vec.pop_back();
			visited[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)	scanf("%d", &num[i]);

	for (int i = 0; i < 4; i++) {
		int temp;  scanf("%d", &temp);
		for (int j = 0; j < temp; j++) oper.push_back(i);
	}

	func(0);

	printf("%d\n%d", maxx, minx);

	return 0;
}
