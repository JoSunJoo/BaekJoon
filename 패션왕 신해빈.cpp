#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int T;	scanf("%d", &T);
	while (T--) {
		int N;	scanf("%d", &N);
		int arr[31] = { 0 };
		vector<string> kind;

		for (int i = 0; i < N; i++) {
			string temp, temp1;
			cin >> temp1 >> temp;
			bool flag = true;
			for (int j = 0; j < kind.size(); j++) {
				if (kind[j] == temp) {
					flag = false;
					arr[j]++;
				}
			}
			if (flag) {
				kind.push_back(temp);
				arr[kind.size() - 1]++;
			}
		}
		unsigned long long res = 1;
		for (int i = 0; i < kind.size(); i++)
			res *= (arr[i] + 1);
		printf("%u\n", res-1);
	}
	return 0;
}
