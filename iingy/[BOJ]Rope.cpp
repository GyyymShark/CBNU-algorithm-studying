#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001] = { 0 };

int main() {
	int N,ans;
	
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	sort(arr, arr + N+1);
	ans = arr[N];
	for (int i = N; i>1; i--) {
		ans = max(ans, arr[i - 1] * (N - i + 2));
	}
	printf("%d\n", ans);

	return 0;
}