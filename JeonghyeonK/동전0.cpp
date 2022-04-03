#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	//동전 갯수, 금액 입력받기
	int N, K;
	cin >> N;
	cin >> K;

	//동전들 얼마짜린지 입력받기
	vector<int> array;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		array.push_back(a);
	}

	//내림차순 정렬
	sort(array.rbegin(), array.rend());

	//동전 갯수 변수
	int coin_num = 0;

	//K에서 동전금액을 빼면서 동전 개수++
	for (int i = 0; K > 0; i++) {
		while (K >= array[i]) {
			K -= array[i];
			coin_num++;
		}
	}

	cout << coin_num;


	return 0;
}