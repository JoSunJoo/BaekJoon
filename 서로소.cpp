#include<stdio.h>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	int N;	 scanf("%d", &N);
	while (N > 0) {
		vector<pair<int, int>> vec;
		int p = 2;
		int cnt = 0;
		while (N > 1) {
			if (N%p == 0) {
				N /= p;
				cnt++;
			}
			else {
				if (cnt > 0)	vec.push_back(make_pair(p, cnt));
				p++;	cnt = 0;
			}
		}
		if (cnt > 0)	vec.push_back(make_pair(p, cnt));

		int result = 1;
		for (int i = 0; i < vec.size(); i++)
			result *= (pow(vec[i].first, vec[i].second) - pow(vec[i].first, vec[i].second - 1));

		printf("%d\n", result);
		scanf("%d", &N);
	}
	return 0;
}
