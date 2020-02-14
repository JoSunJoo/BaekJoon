#include<stdio.h>
#include<algorithm>
using namespace std;
int gcd(int a, int b) {//최대공약수 구하는 함수
	return a % b ? gcd(b, a%b) : b;
}

int main() {
	int T;	scanf("%d", &T);

	while (T--) {
		int A, B;	scanf("%d %d", &A, &B);
		printf("%d\n", (A*B)/gcd(max(A, B), min(A, B))); //최소 공배수 구하는 공식
	}
	return 0;
}
