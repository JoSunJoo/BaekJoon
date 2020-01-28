#include<stdio.h>
#include<algorithm>
#include<utility>
using namespace std;

int N;
pair<int, int> schedule[16];

int cal(int day) {
	if (day == N + 1) return 0;
	if (day > N + 1) return -987654321;
	int result = 0;
	result += max(schedule[day].second + cal(day + schedule[day].first), cal(day + 1));
	return result;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &schedule[i].first, &schedule[i].second);

	printf("%d", cal(1));
	return 0;
}
