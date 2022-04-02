#include <iostream>
#include <deque>
using namespace std;
deque<int> arr;
int count1 = 0;
int location = 0;
int main(void)
{
	int n, m;
	int num;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		arr.push_back(i); //순서대로 삽입
	}
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		for (int j = 0; j < arr.size(); j++)
		{
			if (num == arr[j])
			{
				location = j + 1;
			}
		}
		if (location <= (arr.size() / 2 + 1))
		{
			while (num != arr.front())
			{
				arr.push_back(arr.front());
				arr.pop_front();
				count1++;
			}
			arr.pop_front(); //원소 뽑아내기

		}
		else
		{
			while (num != arr.front())
			{
				arr.push_front(arr.back());
				arr.pop_back();
				count1++;
			}
			arr.pop_front(); //원소 뽑아내기
		}
	}
	cout << count1 << endl;
	return 0;
}