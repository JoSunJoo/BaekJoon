#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

string str;
char wendi[5][5] = { {'.', '.', '*', '.', '.'}, //웬디 프레임
					 {'.', '*', '.', '*', '.'},
					 {'*', '.', '0', '.', '*'},
					 {'.', '*', '.', '*', '.'},
					 {'.', '.', '*', '.', '.'} };

char piter[5][5] = { {'.', '.', '#', '.', '.'}, //피터팬 프레임
					 {'.', '#', '.', '#', '.'},
					 {'#', '.', '0', '.', '#'},
					 {'.', '#', '.', '#', '.'},
					 {'.', '.', '#', '.', '.'} };
char arr[5][70];
int main() {

	cin >> str;
	int point = 0;
	for (int i = 0; i < str.size(); i++) {
		if ((i+1) % 3 == 0) {//웬디 프레임(*)
			for (int x = 0; x < 5; x++) {
				for (int y = point; y < point + 5; y++) {
					arr[x][y] = wendi[x][y - point];
					if (arr[x][y] == '0') arr[x][y] = str[i];
				}
			}
		}
		else {//피터팬 프레임(#)
			bool memo = false; 
			if (arr[2][point] == '*') memo = true;//웬디프레임과 피터팬이 겹치면 웬디가 우선순위를 가짐
			for (int x = 0; x < 5; x++) {
				for (int y = point; y < point + 5; y++) {
					arr[x][y] = piter[x][y - point];
					if (arr[x][y] == '0') arr[x][y] = str[i];
				}
			}
			if (memo) arr[2][point] = '*';
		}
		point += 4;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < str.size() * 4 + 1; j++) 
			printf("%c", arr[i][j]);
		printf("\n");
	}
	return 0;
}