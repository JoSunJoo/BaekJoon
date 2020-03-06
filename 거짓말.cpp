#include<stdio.h>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

int N, M;
vector<int> party[51], people[51];//파티 명단, 사람이 파티에 참석한 명단
vector<int> real;//진실을 아는 사람의 명단
int visited[51] = { 0 };//파티에 대한 visited(1:real이 방문 / 0:거짓말 해도 괜춘!)

int BFS() {
	queue<int> q;//real이 방문하는 파티에 대한 queue
	for (int i = 0; i < real.size(); i++) {//real사람들이 파티를 방문함
		for (int j = 0; j < people[real[i]].size(); j++) {
			if (visited[people[real[i]][j]] == 0) {
				q.push(people[real[i]][j]);
				visited[people[real[i]][j]] = 1;
			}
		}
	}

	while (!q.empty()) {//파티에 참석하는 일반인들을 real로 만들어서 반복함
		int now = q.front();	q.pop();
		for (int i = 0; i < party[now].size(); i++) {
			for (int j = 0; j < people[party[now][i]].size(); j++) {
				if (visited[people[party[now][i]][j]] == 0) {
					q.push(people[party[now][i]][j]);
					visited[people[party[now][i]][j]] = 1;
				}
			}
		}
	}
	int result = 0;
	for (int i = 0; i < M; i++) {
		if (visited[i] == 0) result++;
	}
	return result;
}

int main() {
	scanf("%d %d", &N, &M);
	int a;	scanf("%d", &a);
	while (a--) {
		int temp;	scanf("%d", &temp);
		real.push_back(temp);
	}

	for(int p=0; p<M; p++) {
		scanf("%d", &a);
		for (int i =0; i < a; i++) {
			int temp;	scanf("%d", &temp);
			party[p].push_back(temp);
			people[temp].push_back(p);
		}
	}

	printf("%d", BFS());

	return 0;
}