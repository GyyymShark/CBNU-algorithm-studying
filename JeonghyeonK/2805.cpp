#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


long long N, M;
vector<long long> tree;
long long max_value = 0;
long long min_value = 0;
long long low_height, high_height, max_height = 0;

long long func(long long, long long);

int main() {



	cin >> N >> M;

	for (long long i = 0; i < N; i++) {
		long long a;
		cin >> a;
		tree.push_back(a);
		max_value += a;
		if (a > max_height) max_height = a;
	}

	low_height = 0;
	high_height = max_height;

		long long b = func(high_height, low_height);
		cout << b;
	
	

}

long long func(long long high_height, long long low_height) {
	long long value = 0;
	long long average = (low_height + high_height) / 2;

	for (long long i = 0; i < N; i++) {
		if (tree[i] > average) value += tree[i] - average;
	}

	if (value > M) low_height = average;
	else if (value < M) high_height = average;
	else return average;

	if (high_height - low_height == 1) return low_height;
	else return func(high_height, low_height);
}
