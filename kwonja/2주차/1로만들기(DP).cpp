#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001] = { 0, };
int main(void)
{
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		a[i] = a[i - 1] + 1;
		if (i % 2 == 0)
			a[i] = min(a[i], a[i / 2] + 1);
		if (i % 3 == 0)
			a[i] = min(a[i], a[i / 3] + 1);
	}
	cout << a[n];
	return 0;
}