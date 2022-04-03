#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int num;
	int total = 0;   //총합 저장
	cin >> num;

	vector <int> v(num);

	for (int i = 0; i < num; i++) {   //벡터에 값 넣어줌
		cin >> v[i];
	}

	sort(v.begin(),v.end());  //벡터 오름차순으로 정렬

	for (int j = 0; j < num; j++) {
		total = total + v[j] * (num - j);   //total 을 구함
	}

	cout << total;


	return 0;
}