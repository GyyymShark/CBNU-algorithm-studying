#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001] = { 0,1,2,4, };
int main(void)
{
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		for (int j = 4; j <= k; j++)
		{
			if (a[j] == 0)a[j] = a[j - 1] + a[j - 2] + a[j - 3];
		}
		cout << a[k] << endl;
	}
	return 0;
}