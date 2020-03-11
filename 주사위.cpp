#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	long long n, arr[6], m = 0, t3, t2, t1, sum = 0;
	cin >> n;
	t3 = t2 = t1 = 100000000;
	for (int i = 0; i < 6; sum += arr[i++])	{
		cin >> arr[i];
		m = max(arr[i], m);
		t1 = min(arr[i], t1);//블럭 1개의 최소값 구하기
	}

	for (int i = 0; i < 6; i++)	for (int j = 0; j < 6; j++)//이웃한 2개의 블럭의 최소값 구하기
			if (i != j && (i + j != 5))
				t2 = min(t2, arr[i] + arr[j]);

	for (int i = 2; i <= 3; ++i)//이웃한 3개의 블럭의 최소값 구하기
		t3 = min({ t3, arr[0] + arr[1] + arr[i], arr[1] + arr[5] + arr[i], arr[0] + arr[4] + arr[i] , arr[4] + arr[5] + arr[i] });

	if (n == 1)
		cout << sum - m;
	else
		cout << 4 * (t3 + (2 * n - 3)*t2 + t1 * (n - 2)*(n - 1)) + t1 * (n - 2)*(n - 2);

	return 0;
}