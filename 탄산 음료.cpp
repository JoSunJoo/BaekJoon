#include<stdio.h>

int main(){
	int e, f, c;	scanf("%d %d %d", &e, &f, &c);
	e += f;
	int cnt = 0;
	while(e >= c){
		f = e/c;
		cnt += f;
		e = e%c + f;
	}
	printf("%d", cnt);
	return 0;
}