#include <iostream>
#include<vector>
using namespace std;
int n, s;
vector<int> arr;
int ans = 0;
void func(int depth, int sum)
{
	if (sum == s)
	{
		ans++;
		if (depth != n)
		{
			ans--;    //중간에 원하는숫자가 나올경우, 그 뒤로 원소를 안더하게되면 원하는 수열이 계속 카운트됨.
					  //마지막만 카운트 되도록 설정
		}
	}
	if (depth == n)return;
	func(depth + 1, sum + arr[depth]); //현재 숫자를 더하는 경우
	func(depth + 1, sum);  //현재 숫자를 더하지 않는 경우
}
int main(void)
{
	int input;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr.push_back(input);
	}
	func(0, 0);
	if (s == 0)ans--;  //공집합을 카운트 하지 않음
	cout << ans;
	return 0;
}