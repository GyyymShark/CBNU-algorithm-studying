#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
int l, c;
vector<char> arr;

void func(int consonant, int vowel, int i, int check, string str)
{
	if (str.length() == l)             //원하는문자열 길이가 되면
	{
		if ((consonant >= 1) && (vowel >= 2)) //자음,모음개수를 확인하고
		{
			if (check == 1) //1,0 2가지경우에서 하나만 출력
			{
				cout << str << endl;
				return;
			}
			else
				return;
		}
		else
			return;
	}
	if (i == c)return;
	if (check == 1)
	{
		str += arr[i];
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
		{
			consonant++;
		}
		else
		{
			vowel++;
		}
	}
	func(consonant, vowel, i + 1, 1, str); //선택이 됐을때
	func(consonant, vowel, i + 1, 0, str); //선택이 되지 않았을때
}
int main(void)
{
	char input;
	cin >> l >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());
	func(0, 0, -1, 0, "");

	return 0;
}