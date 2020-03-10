#include<iostream>
#include<algorithm>
using namespace std;

/*
이 문제는 조합에 대한 문제이기 때문에 약분에 의하여 
결과값의 2의 소인수개수가 5의 소인수개수보다 작을 경우가 존재한다!
ex) 125는 2 : 0개 / 5 : 3개

따라서, 2와 5의 소인수개수를 모두 고려할 필요가 있다.
*/

unsigned long long div2(int n) { //2의 소인수개수를 반환하는 함수
	unsigned long long res = 0;
	while (n > 0) {
		n /= 2;
		res += n;
	}
	return res;
}

unsigned long long div5(int n) { //5의 소인수개수를 반환하는 함수
	unsigned long long res = 0;
	while (n > 0) {
		n /= 5;
		res += n;
	}
	return res;
}

int main() {
	unsigned long long n, m, result;
	cin >> n >> m;
	unsigned long long temp = n - m;

	unsigned long long up2 = div2(n), up5 = div5(n); //분자에 대한 소인수개수를 저장
	up2 -= (div2(m) + div2(temp));//분모의 2의 소인수개수를 구하여 개수 차감하기
	up5 -= (div5(m) + div5(temp));//분모의 5의 소인수개수를 구하여 차감하기
	result = min(up2, up5);
	cout << result;
	return 0;
}