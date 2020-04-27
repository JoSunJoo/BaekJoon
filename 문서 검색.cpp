#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

string input, token;
bool check(int point) {
	int p = 0;
	for (int i = point; i < point + token.size(); i++) {
		if (input[i] != token[p++])	return false;
	}
	return true;
}

int main() {
	getline(cin, input);
	getline(cin, token);
	if (input.size() < token.size()) {
		printf("0");
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < input.size()-token.size()+1; i++) {
		if (input[i] == token[0] && check(i)) {
			cnt++;
			i += (token.size()-1);
		}
	}
	printf("%d", cnt);
	return 0;
}
