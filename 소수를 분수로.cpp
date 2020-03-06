#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

/*
이 문제는 중학교때? 배운 순환소수를 분수로 바꾸는 공식을 활용하는 문제이다.
정말 어처구니 없게 나는 long long을 printf("%u");로 출력을 해서 4번 틀리는 기적을 맛보았다...
공식 자체는 인터넷으로 찾아보면 쉽게 이해하리라 생각한다.
*/

long long gcd(long long a, long long b) {//최대공약수 구하는 함수
	return a % b ? gcd(b, a%b) : b;
}

int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		string num;	cin >> num;
		long long up = 0, down = 1; //분자, 분모

		if (num.find("(") == string::npos) {//순환소수가 아닐 경우
			for (int i = 2; i < num.size(); i++) {
				up = up * 10 + (num[i] - '0');
				down *= 10;
			}
		}
		else if (num.find("(") == 2) {//순환소수로 시작하는 경우
			for (int i = 2; i < num.size() - 2; i++)
				down *= 10;
			for (int i = 3; i < num.size() - 1; i++)
				up = up * 10 + (num[i] - '0');
			down--;
		}
		else {
			int point = num.find("(");
			long long temp = 1;
			for (int i = 2; i < num.size() - 1; i++)
				if (num[i] != '(')	up = up * 10 + (num[i] - '0');
			for (int i = 2; i < num.size() - 2; i++)
				down *= 10;
			for (int i = 2; i < point; i++)
				temp *= 10;
			down -= temp;
			temp = 0;
			for (int i = 2; i < point; i++)
				temp = temp * 10 + (num[i] - '0');
			up -= temp;
		}
		cout << up / gcd(down, up) << '/' << down / gcd(down, up) << '\n';
	}
	return 0;
}
