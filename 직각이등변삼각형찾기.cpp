#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

/*
이 문제는 정말 단순 빡구현 문제이다...(푸는데만 2시간이 넘게 걸림ㄷㄷ)
간략하게 설명하는 알고리즘은 다음과 같다.
1. 꼭지점이 3개인지 구한다.
2. 꼭지점의 길이를 통해 직각이등변삼각형인지 판별한다.
3. 직각이등변삼각형의 속이 1로 차있는지 확인한다(이게 정말 왓더헬..)
4. 추가로 예외적인 수가 있는지 검토한다(ex. 삼각형 밖에 1이 있다던가 etc)
*/

int d[11][11];
bool visit[11][11];
int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 }, dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 }, color;
void input() {
	for (int i = 1; i <= 10; ++i)
		for (int j = 1; j <= 10; ++j)
			scanf("%1d", &d[i][j]);
}
struct coor {
	int x, y;
	coor() :x(0), y(0) {};
	coor(int _x, int _y) :x(_x), y(_y) {};
};
vector<coor> v[52];
int count_array[52];
bool cmp(const coor &a, const coor &b) {
	if (a.x < b.x) return true;
	else if (a.x == b.x) {
		if (a.y < b.y) return true;
		else return false;
	}
	else return false;
}
void dfs(int row, int col, int color) {
	if (row < 1 || row>10 || col > 10 || col < 1) return;
	if (visit[row][col] || !d[row][col]) return;
	d[row][col] = color, visit[row][col] = true;
	for (int i = 0; i < 4; ++i) {
		int nr = row + dx[i], nc = col + dy[i];
		dfs(nr, nc, color);
	}
}
int vec(const coor &a, const coor & b) { //내적
	return (a.x*b.x + a.y*b.y);
}
int val(const coor &a) { //벡터의 크기
	return (a.x*a.x + a.y*a.y);
}
bool check(const coor &a, const coor &b, const coor &c, int color) {
	int check = 0;
	if (val(a) == 0 && val(b) == 0 && val(c) == 0) return false;
	coor ab(b.x - a.x, b.y - a.y), ac(c.x - a.x, c.y - a.y), bc(c.x - b.x, c.y - b.y);
	//check가 2이면 수평,수직인 선분으로 이루어 진 삼각형
	if (ab.x == 0 || ab.y == 0) check++;
	if (bc.x == 0 || bc.y == 0) check++;
	if (ac.x == 0 || ac.y == 0) check++;
	int amount = 0;
	if (vec(ab, ac) == 0) {
		if (val(ab) == val(ac)) {
			if (check == 2) amount = ((abs(ab.x + ab.y) + 1)*(abs(ab.x + ab.y) + 1) + (abs(ab.x + ab.y) + 1)) / 2;
			else amount = (abs(bc.x + bc.y) + 2)*(abs(bc.x + bc.y) + 2) / 4;
			if (count_array[color] == amount) return true;
			else return false;
		}
	}
	if (vec(ab, bc) == 0) {
		if (val(ab) == val(bc)) {
			if (check == 2) amount = ((abs(ab.x + ab.y) + 1)*(abs(ab.x + ab.y) + 1) + (abs(ab.x + ab.y) + 1)) / 2;
			else amount = (abs(ac.x + ac.y) + 2)*(abs(ac.x + ac.y) + 2) / 4;
			if (count_array[color] == amount) return true;
			else return false;
		}
	}
	if (vec(ac, bc) == 0) {
		if (val(ac) == val(bc)) {
			if (check == 2) amount = ((abs(ac.x + ac.y) + 1)*(abs(ac.x + ac.y) + 1) + (abs(ac.x + ac.y) + 1)) / 2;
			else amount = (abs(ab.x + ab.y) + 2)*(abs(ab.x + ab.y) + 2) / 4;
			if (count_array[color] == amount) return true;
			else return false;
		}
	}
	return false;
}
int main() {
	input();
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (d[i][j] && !visit[i][j]) {
				color++;
				dfs(i, j, color); //dfs를 사용하여 점들의 집합을 정의 한다
			}
		}
	}
	int count_triangle = 0, ans_color = 0;;
	for (int c = 1; c <= color; ++c) {
		int count = 0, total_count = 0;
		for (int row = 1; row <= 10; ++row) {
			for (int col = 1; col <= 10; ++col) {
				if (d[row][col] == c) {
					total_count++, count = 0;
					for (int k = 0; k < 8; ++k) {
						int nr = row + dx[k], nc = col + dy[k];
						if (nr < 1 || nr>10 || nc < 1 || nc>10) continue;
						if (d[nr][nc] == c) count++;
					}
					if (count == 2 || count == 3) v[c].push_back(coor(row, col));
				}
			}
		}
		count_array[c] = total_count;
		if (v[c].size() == 3) {//꼭지점이 3개이며
			if (check(v[c][0], v[c][1], v[c][2], c)) {//직각 이등변 삼각형 조건을 만족한다면
				count_triangle++; //전체 삼각형의 계수를 증가
				ans_color = c; // 몇번째 집합인지를 저장
			}
		}
	}
	if (count_triangle == 1) {//만들 수 있는 삼각형의 개수가 1개 일 시
		sort(v[ans_color].begin(), v[ans_color].end(), cmp);
		for (int i = 0; i < 3; i++) {
			cout << v[ans_color][i].x << " " << v[ans_color][i].y << "\n";
		}
	}
	else cout << "0" << "\n";
	return 0;
}