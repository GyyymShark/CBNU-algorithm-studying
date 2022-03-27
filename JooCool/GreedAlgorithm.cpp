// 회의실 배정 알고리즘 (그리드, 우선순위 큐)
// 시작, 끝시간 pair 이용해서 입력받음 
// sort(시작시간 오름차순) 으로 정렬  
// 같은 시간일떄 끝나는 시간 오름차순 정렬

#include <iostream>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

typedef pair <int, int> intpair;

int main()

{
	int cnt = 0;
	int n;
	cin >> n;
	intpair* v = new intpair[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i].first, v[i].second; // 회의 시작시간 끝시간들을 n번 입력받음
	}
	sort(v, v + n + 1);
	priority_queue<int, vector<int>, greater<int>>pq; // 우선순위 큐를 사용해서 정렬
	pq.push(v[0].second); //정렬을 했으니까, 맨 처음끝나는 시간을 넣는다.

	int start, end;
	for (int i = 1; i <= n; i++)
	{
		start = v[i].first;
		end = v[i].second;
		if (pq.top() > start)
		{
			pq.push(end);
		}	//수업중인 강의실의 끝나는 시간 > 다음 수업 시작시간 => 강의실 추가
		else
		{
			pq.pop();	// 아니면 팝
			pq.push(end);
		}
	}
	cout << pq.size() << endl;
	return 0;
}