#include<stdio.h>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
pair<int, int> arr[3000];
int ratio[3000];
int N;
int visited[3000] = { 0 };

bool cal(int x, int y, int r) {
	return r * r >= (x*x + y * y);
}

void BFS(pair<int, int> point, int r) {
	queue<pair<int, int>> q;
	queue<int> circle;
	q.push(point); circle.push(r);

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;  q.pop();
		int r = circle.front();  circle.pop();

		for (int i = 0; i < N; i++) {
			if (visited[i] == 0 && cal(arr[i].first - x, arr[i].second - y, ratio[i]+r)) {
				q.push(make_pair(arr[i].first, arr[i].second));
				circle.push(ratio[i]);
				visited[i] = 1;
			}
		}
	}
}

int main() {
	int T;	scanf("%d", &T);

	while (T--) {
		int result = 0;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			int x, y, temp;	 scanf("%d %d %d", &x, &y, &temp);
			arr[i].first = x;  arr[i].second = y; ratio[i] = temp;
			visited[i] = 0;
		}

		for (int i = 0; i < N; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				BFS(arr[i], ratio[i]); result++;
			}
		}

		printf("%d\n", result);
	}

	return 0;
}
