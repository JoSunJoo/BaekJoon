#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

int N, K;
vector<pair<int, int>> jewelry;
vector<int> bag;

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int a, b;	scanf("%d %d", &a, &b);
		jewelry.push_back(make_pair(a, b));
	}

	for (int i = 0; i < K; i++) {
		int temp;	scanf("%d", &temp);
		bag.push_back(temp);
	}

	sort(jewelry.begin(), jewelry.end());
	sort(bag.begin(), bag.end());

	unsigned long long result = 0;
	priority_queue<int> pq;//가방에 담는 주얼리의 값에 대한 우선순위큐
	int point = 0;//주얼리의 포인터
	for (int i = 0; i < K; i++) {
		while (point < N && jewelry[point].first <= bag[i]) {
			pq.push(jewelry[point].second);
			point++;
		}

		//각 가방에 담겨있을 수 있는 값 중 가장 큰 값을 선택한다.
		//나머지는 다음 가방에 넣음!(가방에는 1개의 주얼리만 담을 수 있다.)
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;
	return 0;
}
