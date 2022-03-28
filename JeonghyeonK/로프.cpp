#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	//로프 갯수 입력받기
	int N;
	cin >> N;

	//로프별 중량 입력받기
	vector<int> array;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		array.push_back(a);
	}

	//내림차순 정렬
	sort(array.rbegin(), array.rend());

	//중량 총 합의 최댓값 변수
	int max_sum = 0;
	
	//vector 원소 하나씩 거치면서 최대값 찾기
	for (int i = 0; i < N; i++) {
		int sum = array[i] * (i + 1);
		max_sum = max(max_sum, sum);
	}

	cout << max_sum;


	return 0;
}