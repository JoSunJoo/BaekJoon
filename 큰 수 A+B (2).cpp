#include<stdio.h>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
	stack<int> a, b, res;
	int up = 0;

	char c;	scanf("%c", &c);
	while (c >= '0' && c <= '9') {
		a.push(c - '0');
		scanf("%c", &c);
	}

	char ch;	scanf("%c", &ch);
	while (ch >= '0' && ch <= '9') {
		b.push(ch - '0');
		scanf("%c", &ch);
	}

	int limit = min(a.size(), b.size());
	for (int i = 0; i < limit; i++) {
		up += a.top() + b.top();
		a.pop(); b.pop();
		res.push(up%10);
		up /= 10;
	}

	while (a.size() > 0) {
		up += a.top();	a.pop();
		res.push(up % 10);	up /= 10;
	}

	while (b.size() > 0) {
		up += b.top();	b.pop();
		res.push(up % 10);	up /= 10;
	}

	while (up > 0) {
		res.push(up % 10); up /= 10;
 	}
	while (!res.empty()) {
		printf("%d", res.top()); res.pop();
	}
	return 0;
}
