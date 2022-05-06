#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
int main(void)
{

	long long n, m;
	long long input;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());
	long long top = arr[arr.size() - 1];
	long long bottom = 0;
	long long middle = 0;
	long long sum = 0;
	long long result;
	while (top >= bottom)
	{
		sum = 0;
		middle = (top + bottom) / 2;
		for (int i = 0; i < n; i++)
		{
			if ((arr[i] - middle) >= 0)
			{
				sum += (arr[i] - middle); //가져갈수 있는 나무길이
			}
		}
		if (sum >= m)
		{
			result = middle;
			bottom = middle + 1;
		}
		else
		{
			top = middle - 1;
		}
	}
	cout << result;

	return 0;
}