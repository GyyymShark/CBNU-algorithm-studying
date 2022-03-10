#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001] = { 0, };
int main(void)
{
	int n;
	cin >> n;
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		// N=N-1 + N-2
		a[i] = ((a[i - 1] + a[i - 2]) % 10007);
	}
	cout << a[n];
	return 0;
}