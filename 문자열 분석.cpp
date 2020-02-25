#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

/*
string 타입의 경우에는
getline(cin, '변수명') 을 사용하여 공백을 포함한 한 줄을 입력받을 수 있다.
또한, eof입력시, 1이 아닌 다른 값을 반환하여 while()문을 탈출할 수 있다.
*/

string str;
int up = 0, down = 0, num = 0, space = 0;
int main() {
    while (getline(cin, str, '\n')) {
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z')
                up++;
            else if (str[i] >= 'a' && str[i] <= 'z')
                down++;
            else if (str[i] == ' ')
                space++;
            else
                num++;
        }
		printf("%d %d %d %d\n", down, up, num, space);
		up = down = num = space = 0;
    }
}
