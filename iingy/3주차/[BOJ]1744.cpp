/* 백준 1744 수 묶기
   By Evergyu*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int sum = 0, N, array[51] = { -99 }, j = 1;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> array[i];
	}
	sort(array, array + N);
	while (array[j] <= 0) {
		++j;
	}
}