#include <iostream>
using namespace std;

int coin[11]={0,};
int c = 0;
int main() {
	int N,K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> coin[i];
	}
	
	for (int i = N; i > 0; i--) {
		int ans;
		if (K == 0) break;
		if (K >= coin[i]) {
			ans = K / coin[i];
			K = K%coin[i];
			c += ans;
		}
	}
	printf("%d", c);
}