#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int gcd(int a, int b) { //최대공약수 구하기(유클리드 호제법)
	return a % b ? gcd(b, a%b) : b;
}

int arr[100] = { 0 };
int main() {
	int N;	scanf("%d", &N);
	for (int i = 0; i < N; i++)	scanf("%d", &arr[i]);

	sort(arr, arr+N);

	int maxi = arr[1] - arr[0];
	for (int i = 2; i < N; i++)
		maxi = gcd(maxi, arr[i] - arr[i - 1]);

	vector<int> vec;
	for (int i = 1; i*i <= maxi; i++) {
		if (maxi%i == 0) {
			vec.push_back(i);
			if (i != maxi / i) vec.push_back(maxi/i);
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 1; i < vec.size(); i++) printf("%d ", vec[i]);

	return 0;
}
