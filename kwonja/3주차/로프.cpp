#include <iostream>
#include <algorithm>
#include <vector>
//모든 로프를 사용할필요가 없이 최대를 구해야한다.
using namespace std;

int main() {
	int n, w, max = 0;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		cin >> w;
		arr.push_back(w);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
	{
		if (arr[i] * (n - i) > max)
		{
			max = arr[i] * (n - i);
		}
	}
	cout << max;
	return 0;
}