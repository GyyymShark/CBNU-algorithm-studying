#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	//사람 수 입력받기
	int N;
	cin >> N;

	//사람마다 걸리는 시간 입력받기
	vector<int> array;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		array.push_back(a);
	}

	//내림차순 정렬
	sort(array.rbegin(), array.rend());

	//시간의 합 변수
	int time_sum = 0;

	//K에서 동전금액을 빼면서 동전 개수++
	for (int i = 1; i <= N; i++) {
		time_sum += array[i - 1] * i;
	}

	cout << time_sum;


	return 0;
}