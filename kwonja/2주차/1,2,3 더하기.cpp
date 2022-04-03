#include <iostream>
using namespace std
int min = 0;
int func(int cnt, int num)
{
	if (num < 1)return 0;
	if (num == 1)
	{
		if (min == 0)min = cnt;
		else if (min > cnt)min = cnt;
	}
	if ((num % 3) == 0)
		func(cnt + 1, num / 3);
	if ((num % 2) == 0)
		func(cnt + 1, num / 2);
	func(cnt + 1, num - 1);
}
int main(void)
{
	int n;
	cin >> n;
	func(0, n);
	cout << min << endl;
	return 0;
}