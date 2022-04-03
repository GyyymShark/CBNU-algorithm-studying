#include <iostream>
#include <math.h>

using namespace std;

int divide_1st(int n, int limit_2, int limit_3);

int divide(int n, int limit_2, int limit_3);

int main() {

	int n;

	cin >> n;
	cout << divide_1st(n, 19, 12) << endl;

	return 0;
}

int divide_1st(int n, int limit_2, int limit_3) {

	int a;
	int max = 0;
	int max_2 = 0;
	int max_3 = 0;

	for (int i = 0; i <= limit_2; i++) {
		a = pow(2, i);
		for (int j = 0; j <= limit_3 && a <= n; j++) {
			a *= pow(3, j);
			if (a > max && a <= n) {
				max = a;
				max_2 = i;
				max_3 = j;
			}
		}

	}

	return max_2 + max_3 + divide(n - max, max_2, max_3);
}

int divide(int n, int limit_2, int limit_3) {

	int a;
	int max = 0;
	int max_2 = 0;
	int max_3 = 0;

	for (int i = 0; i <= limit_2; i++) {
		a = pow(2, i);
		for (int j = 0; j <= limit_3 && a <= n; j++) {
			a *= pow(3, j);
			if (a > max && a <= n) {
				max = a;
				max_2 = i;
				max_3 = j;
			}
		}

	}
	
	if (n - max != 0) return 1 + divide(n - max, max_2, max_3);
	else return 0;
}