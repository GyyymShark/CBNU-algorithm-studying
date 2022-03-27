#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int num;
	cin >> num;
	
	int big = 0;  //최대치를 저장할 변수
	int* save = new int[num];

	for (int i = 0; i < num; i++) {
		cin >> save[i];
	}

	sort(save,save+num);

	/*for (int j = 0; j < num; j++) {
		cout << save[j];
	} */ //sort 정렬 확인

	for (int i = 0; i < num; i++) {   
		int sum = save[i] * (num - i);  //가장 작은 수를 포함한 인덱스의 수만큼 곱하여 최대치를 구하여 기존 최대치와 비교
		if (sum >= big) {
			big = sum;
		}
	}

	cout << big;


	delete[] save;

	return 0;
}