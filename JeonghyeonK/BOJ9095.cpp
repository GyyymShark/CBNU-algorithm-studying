#include<iostream>

using namespace std;

int divide(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 4;
	else {
		return divide(n - 1) + divide(n - 2) + divide(n - 3);
	}

}

int main() {
	int T = 0;
	int n = 0; 

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << divide(n) << endl;
	}

	return 0;

}