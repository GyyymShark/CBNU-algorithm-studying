#include <iostream>
using namespace std;
void func1(int num, int start, int mid, int end)
{
	if (num == 1)
	{
		printf("%d %d\n", start, end);
		return;
	}
	func1(num - 1, start, end, mid);
	printf("%d %d\n", start, end);
	func1(num - 1, mid, start, end);
}
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	func1(n, 1, 2, 3);
	return 0;
}