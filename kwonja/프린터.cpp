#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using namespace std;
deque<pair<int, int>> a;
bool m = false;
int count = 0;
int solution(vector<int> priorities, int location)
{
	for (int i = 0; i < priorities.size(); i++)
	{
		a.push_back(make_pair(priorities[i], i));         //중요도에 순서를 기억하기위해 pair 선언
	}
	while (!a.empty())
	{
		for (int i = 1; i < a.size(); i++)
		{
			if (m == true)     //이동후 처음부터 비교하기위해 i=1부터 비교
			{
				i = 1;
				m = false;
			}
			if (a[0].first < a[i].first)         // 맨 왼쪽과 나머지를 비교하는데, 맨 왼쪽보다 중요도가 높은게 오른쪽에 있으면
			{ 
				a.push_back(a.front());             //맨 앞에있는것을 맨뒤로 보냄
				a.pop_front();                       
				m = true;                            //맨뒤로 보내고 나서 다시 비교를 시작
			}
		}
		count++;                                       //프린팅을할때 횟수 카운트
		if ((a[0].second) == location)return count;       //원하는 종이가 프린트될때 그 횟수를 출력
		a.pop_front();                                    //원하는 종이가 아니면 삭제후 넘어감
	}
}