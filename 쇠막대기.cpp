#include<stdio.h>
#include<stack>
using namespace std;

stack<char> s;

int main() {
	char now;	scanf("%c", &now);
	char last;
	int cnt = 0, res = 0;
	while (now != '\n') {
		if (now == '(') {
			s.push(now);
			cnt++;
		}
		else {
			s.pop();
			cnt--;
			if (last == '(') {
				res += cnt;
			}
			else
				res++;
		}
		last = now;
		scanf("%c", &now);
	}
	printf("%d", res);
	return 0;
}
