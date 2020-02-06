#include<stdio.h>
#include<queue>
using namespace std;

int N;
int K;
int visited[100002] = { 0 };

void BFS() {
	queue<int> q;
	q.push(N);
	while (!q.empty()) {
		int now = q.front();	q.pop();

		if (now == K) break;

		if (now - 1 >= 0 && visited[now-1] == -1) {
			visited[now - 1] = visited[now] + 1;
			q.push(now - 1);
		}
		if (now + 1 <= K+1 && visited[now+1] == -1) {
			visited[now + 1] = visited[now] + 1;
			q.push(now + 1);
		}
		if (now * 2 <= K+1 && visited[now*2] == -1) {
			visited[now * 2] = visited[now] + 1;
			q.push(now * 2);
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i <= 100000; i++) visited[i] = -1;
	BFS();
	printf("%d", visited[K]+1);
	return 0;
}
