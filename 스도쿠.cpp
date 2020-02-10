#include <stdio.h>
#include<iostream>
using namespace std;
int sudoku[10][10];
bool chk_row[10][10];
bool chk_col[10][10];
bool chk_square[10][10];

int square(int x, int y){
	return (x / 3) * 3 + (y / 3);
}

void DFS(int cnt){
	if (cnt == 81)	{
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)	printf("%d ", sudoku[i][j]);
			printf("\n");
		}
		exit(0);
	}

	int x = cnt / 9, y = cnt % 9;

	if (sudoku[x][y] != 0)	DFS(cnt + 1);
	else{
		for (int i = 1; i <= 9; i++){
			if (chk_row[x][i] == 0 && chk_col[y][i] == 0 && chk_square[square(x, y)][i] == 0)
			{
				chk_row[x][i] = chk_col[y][i] = chk_square[square(x, y)][i] = true;
				sudoku[x][y] = i;
				DFS(cnt + 1);
				sudoku[x][y] = 0;
				chk_row[x][i] = chk_col[y][i] = chk_square[square(x, y)][i] = false;
			}
		}
	}
}

int main(){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++)	{
			scanf("%d", &sudoku[i][j]);
			if (sudoku[i][j] != 0)	{
				chk_row[i][sudoku[i][j]] = true;
				chk_col[j][sudoku[i][j]] = true;
				chk_square[square(i, j)][sudoku[i][j]] = true;
			}
		}
	}
	DFS(0);
	return 0;
}
