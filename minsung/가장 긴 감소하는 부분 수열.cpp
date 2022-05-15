#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001] = { 0 };
int dp[1001] = { 0 };

int main() {

	int num;
	cin >> num;
	
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	

	for (int i = 0; i < num; i++) {		
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	/* 개별 값 확인
	for (int i = 0; i < num; i++) {
		cout << dp[i];
	}
	*/


	int answer = 0;
	for (int i = 0; i < num; i++) {
		if (dp[i] > answer) {
			answer = dp[i];
		}
	}

	cout << answer;
	return 0;
}