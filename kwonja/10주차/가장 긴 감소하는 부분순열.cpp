#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001] = { 0, };
int LDS[1001] = { 0, };  //Longest Decreasing Subsequence
int main(void)
{
	int n;
	cin >> n;
	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr[i] = input;
	}

	for (int i = 0; i < n; i++)
	{
		LDS[i] = 1; //본인 스스로는 길이가 1이다.
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
			{
				if (LDS[i] < (LDS[j] + 1))
				{
					LDS[i] = LDS[j] + 1;
				}
			}
		}
	}
	int max = LDS[0];
	for (int i = 0; i < n; i++)
	{
		if (LDS[i] > max)
		{
			max = LDS[i];
		}
	}
	cout << max;
	return 0;
}