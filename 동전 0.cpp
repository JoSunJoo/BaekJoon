#include<stdio.h>
#include<stack>
using namespace std;

int N, K;
stack<int> s;
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int temp; scanf("%d", &temp);
		s.push(temp);
	}
	int cnt = 0;

	while (K > 0) {
		int num = s.top();	s.pop();
		while (num <= K) {
			K -= num; cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}
