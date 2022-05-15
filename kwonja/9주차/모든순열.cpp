#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int visitied[8] = { 0, };
int n;

void DFS()
{
	if (arr.size() == n)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++)
	{
		if (!visitied[i])
		{
			visitied[i] = 1;
			arr.push_back(i + 1);
			DFS();
			visitied[i] = 0;
			arr.pop_back();

		}
	}
}
int main(void)
{
	cin >> n;
	DFS();
	return 0;
}