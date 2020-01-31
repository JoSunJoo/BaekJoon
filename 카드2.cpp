#include<stdio.h>
#include<deque>
using namespace std;
int N;
deque<int> vec;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) vec.push_back(i);

	while (vec.size() > 1) {
		vec.pop_front();
		int temp = vec.front();
		vec.pop_front();
		vec.push_back(temp);
	}
	printf("%d", vec[0]);
	return 0;
}
