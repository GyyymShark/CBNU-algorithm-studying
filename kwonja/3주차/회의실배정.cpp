#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<pair<long long, long long >> arr;
bool compare(pair<long long, long long> a, pair<long long, long long> b)
{
	if (a.second == b.second)              //0 1   1 1 인 경우를 생각해줘야한다. 문제에서 시작과 끝이 같은 경우도 있다고 하네요 ㅠㅠ
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main(void)
{
	int count = 0;
	long long max = 0;
	int n;
	long long start, end;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		arr.push_back(make_pair(start, end));
	}
	sort(arr.begin(), arr.end(), compare);  //시작순서를 기억하고, 끝나는시간순으로 정렬
	max = arr[0].second;
	count++;
	for (int i = 1; i < n; i++)
	{
		if (arr[i].first >= max)
		{
			count++;
			max = arr[i].second;
		}
	}
	cout << count;
	return 0;
}