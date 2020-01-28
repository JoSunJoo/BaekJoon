#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

int arr[5];
int main() {
	string N; cin >> N;
	bool flag = false;
	int sum = 0;

	for (int i = 0; i < N.size(); i++) {
		int temp = (N[i] - '0');
		if (temp == 0) flag = true;
		sum += temp;
	}

	if (sum % 3 != 0 || !flag)	printf("-1");
	else {
		sort(N.begin(), N.end(), greater<int>());
		cout << N << "\n";
	}
	return 0;
}
