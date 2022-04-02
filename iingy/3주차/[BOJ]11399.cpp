#include <iostream>
#include <algorithm>
using namespace std;
int P[1001] = { -1 };

int main() {
	int N,sum=0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}
	sort(P, P + N+1);
	for (int i = 1; i <= N; i++) {
		sum += P[i] * (N - i + 1);
	}
	printf("%d", sum);
	return 0;
}