#include<vector>
#include<utility>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

//문제에 정의된대로 비교함수 정의하기
bool compare(pair<pair<string, int>, pair<int, int>> a, pair<pair<string, int>, pair<int, int>> b) {
	if (a.first.second != b.first.second) return a.first.second > b.first.second;
	else if (a.second.first != b.second.first) return a.second.first < b.second.first;
	else if (a.second.second != b.second.second) return a.second.second > b.second.second;
	else return a.first.first < b.first.first;
}

int main() {
	vector<pair<pair<string, int>, pair<int, int>>> vec;
	int N;	scanf("%d", &N);
	while (N--) {
		string name; int a, b, c;
		cin >> name >> a >> b >> c;
		vec.push_back(make_pair(make_pair(name, a), make_pair(b, c)));
	}
	sort(vec.begin(), vec.end(), compare);//정의한 비교함수대로 정렬!(algorithm에 있음)
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i].first.first << '\n';
	return 0;
}
