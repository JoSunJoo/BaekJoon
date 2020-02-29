#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main() {
	string str;
	cin >> str;

	while (str != "0") {
		int temp = 0;
		for (int i = 0; i < str.size(); i++) {
			temp *= 10;
			temp += str[i] - '0';
		}
		printf("%d ", temp);
		while (temp > 9) {
			int num = 1;
			while (temp > 0) {
				num *= temp % 10; temp /= 10;
			}
			temp = num;
			printf("%d ", temp);
		}
		printf("\n");
		cin >> str;
	}
	return 0;
}
