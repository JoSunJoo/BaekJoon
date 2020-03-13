#include<stdio.h>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int N, M;	
vector<int> box, crain;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp; scanf("%d", &temp);
		crain.push_back(temp);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int temp; scanf("%d", &temp);
		box.push_back(temp);
	}
	//내림차순 정렬
	sort(box.begin(), box.end(), greater<int>());
	sort(crain.begin(), crain.end(), greater<int>());

	if (box[0] > crain[0]) //들 수 없을 경우
		printf("-1");

	else {
		int result = 0;
		while (!box.empty()) {
			int crain_idx = 0;//crain의 해당 인덱스
			for (int i = 0; i < box.size(); i++) {
				if (crain_idx == crain.size()) break;//모든 crain이 작동하면 for문 종료
				if (crain[crain_idx] >= box[i]) {//해당 crain이 박스를 들을 수 있으면
					box.erase(box.begin()+i); //box의 i번째 항목 삭제
					i--;//박스개수가 감소하기때문에 인덱스를 옮겨줘야함!
					crain_idx++;
				}
			}
			result++;
		}
		printf("%d", result);
	}

	return 0;
}
