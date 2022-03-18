#include <iostream>
using namespace std;

int minindex = 0;
void func(int cnt, int num)
{
	if (num < 1)return;
	if (num == 1)
	{
		if (minindex == 0)minindex = cnt;
		else if (minindex > cnt)minindex = cnt;
		return;
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
	cout << minindex << endl;
	return 0;
}