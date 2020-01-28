#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int a[300002] = { 0 }, b[300002] = { 0 };
int result[600002] = { 0 };

int main() {
	string A, B; cin >> A >> B;

	for (int i = 0; i < A.size(); i++) a[A.size() - 1 - i] = A[i] - '0';
	for (int i = 0; i < B.size(); i++) b[B.size() - 1 - i] = B[i] - '0';

	int idx; int upNum=0;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			idx = i + j;
			int temp = a[i] * b[j] + result[idx] + upNum;
			result[idx]	= temp % 10; upNum = temp/10;
			if (j == B.size() - 1) {
				while (upNum > 0) {
					upNum += result[++idx];
					result[idx] = upNum % 10;
					upNum /= 10;
				}
			}
		}
	}

	for (int i = idx; i >=0; i--) printf("%d", result[i]);
	return 0;
}

===================================python=======================================

import sys

nlist = [int(x) for x in sys.stdin.readline().split()]
print(nlist[0]*nlist[1])
