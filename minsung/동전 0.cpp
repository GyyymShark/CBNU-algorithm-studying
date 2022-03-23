#include <iostream>
using namespace std;

int main() {

	int num, money;
	int count = 0;
	int mook = 0;

	cin >> num >> money;

	int* save = new int[num];

	for (int i = 0; i < num; i++) {
		cin >> save[i];
	}

		
	for (int j = num - 1; j >= 0; j--) {
			count += money / save[j];
			money = money % save[j];
	}

	cout << count;

		delete[] save;

	return 0;
}