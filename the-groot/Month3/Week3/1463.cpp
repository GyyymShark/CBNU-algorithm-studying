/*
#include <iostream>
#define MAX 1000001

using namespace std;

int dp[MAX];

int min(int a, int b) {
	if (a <= b)
		return a;
	else
		return b;
}


int main() {

	int n;
	cin >> n;

	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0 || i % 3 == 0) {
			int temp1;
			int temp2;
			int minimum;
			if (i % 2 == 0 && i % 3 == 0) {
				temp1 = dp[i / 2] + 1;
				temp2 = dp[i / 3] + 1;
				minimum = min(temp1, temp2);
				dp[i] = minimum;
			}
			else if (i % 2 == 0) {
				temp1 = dp[i / 2] + 1;
				temp2 = dp[i - 1] + 1;
				minimum = min(temp1, temp2);
				dp[i] = minimum;
			}
			else {
				temp1 = dp[i / 3] + 1;
				temp2 = dp[i - 1] + 1;
				minimum = min(temp1, temp2);
				dp[i] = minimum;
			}
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}


	cout << dp[n];




	return 0;
}
*/


#include <iostream>
#define MAX 1000001

using namespace std;

int dp[MAX];

int min(int a, int b) {
	if (a <= b)
		return a;
	else
		return b;
}

void calc(int cur, int n) {
	if (cur == n + 1) {
		return;
	}
	else {
		
			dp[cur] = dp[cur - 1] + 1;
			if (cur % 2 == 0)
				dp[cur] = min(dp[cur], dp[cur / 2] + 1);
			if (cur % 3 == 0)
				dp[cur] = min(dp[cur], dp[cur / 3] + 1);
			calc(cur + 1, n);
		
	}

}


int main() {

	int n;
	cin >> n;

	

	calc(2, n);

	

	cout << dp[n];




	return 0;
}