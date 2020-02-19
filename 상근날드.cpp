#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int temp;
	int burger = 3000, drink = 3000;
	for (int i = 0; i < 3; i++) { //버거의 최소값 구하기
		scanf("%d", &temp);
		burger = min(burger, temp);
	}
	for (int i = 0; i < 2; i++) { //음료의 최소값 구하기
		scanf("%d", &temp);
		drink = min(drink, temp);
	}

	printf("%d", burger + drink - 50);//세트메뉴는 -50원 할인
	return 0;
}
