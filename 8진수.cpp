#include<stdio.h>
#include<queue>
#include<string>
#include<iostream>
using namespace std;

queue<int> eight;
int main() {

	string s;  cin >> s;
	if (s.size() % 3 == 0) {
		for (int i = 0; i < s.size(); i += 3) {
			int temp = 0;
			if (s[i] == '1') temp += 4;
			if (s[i + 1] == '1') temp += 2;
			if (s[i + 2] == '1') temp += 1;
			eight.push(temp);
		}
	}
	else if (s.size() % 3 == 1) {
		int temp = 1; eight.push(temp);
		for (int i = 1; i < s.size(); i += 3) {
			temp = 0;
			if (s[i] == '1') temp += 4;
			if (s[i + 1] == '1') temp += 2;
			if (s[i + 2] == '1') temp += 1;
			eight.push(temp);
		}
	}
	else {
		int temp = 0;
		if (s[0] == '1') temp += 2;
		if (s[1] == '1') temp += 1;
		eight.push(temp);
		for (int i = 2; i < s.size(); i += 3) {
			temp = 0;
			if (s[i] == '1') temp += 4;
			if (s[i + 1] == '1') temp += 2;
			if (s[i + 2] == '1') temp += 1;
			eight.push(temp);
		}
	}

	while (!eight.empty()) {
		printf("%d", eight.front());
		eight.pop();
	}

	return 0;
}
