#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

/*
from : 출발 위치
by : 사용 안하는 기둥
to : 도착 위치
*/

vector<pair<int, int> > v;//결과값 저장 벡터
void hanoi(int n, int from, int by, int to) {
	if (n == 1) v.push_back(make_pair(from, to));
	else {
		hanoi(n - 1, from, to, by);//비어있는 기둥으로 옮김
		v.push_back(make_pair(from, to));//결과값 삽입
		hanoi(n - 1, by, from, to);//최종 기둥으로 옮김
	}
}
int main() {
	int n;
	scanf("%d", &n);
	hanoi(n, 1, 2, 3);
	printf("%d\n", v.size());

	for (int i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);

	return 0;
}