#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int arr[8][8] = { 0, };
int visitied[8][8] = { 0, };
int n, m;
int wall = 0;
int virus = 0;
int add_virus = 0;
int result = 0;
vector<pair<int, int>> way;
deque<pair<int, int>> q;

//바이러스가 퍼질수 있는 경우의 수
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int BFS()
{
	add_virus = 0;                              //매 경우 확산되는 바이러스가 다르기때문에 초기화
	for (int i = 0; i < n; i++)                 //모든경우를 돌아야하기때문에 BFS를 초기화 시켜줘야함
		for (int j = 0; j < m; j++)
			visitied[i][j] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((arr[i][j] == 2) && (visitied[i][j] == 0)) //방문하지 않은 바이러스를 방문
			{
				visitied[i][j] = 1; //방문
				q.push_back(make_pair(i, j));
			}
		}
	}
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (int k = 0; k < 4; k++)
		{
			int next_x = x + dx[k];
			int next_y = y + dy[k];

			if ((next_x < 0) || (next_x >= n) || (next_y < 0) || (next_y >= m)) continue;            //좌표를 벗어나면 제외

			if ((arr[next_x][next_y] == 0) && (!visitied[next_x][next_y])) //확산
			{
				//arr[next_x][next_y] = 2;  --> 기존배열이 바뀐다.
				add_virus++; //추가 바이러스 계산
				visitied[next_x][next_y] = 1;
				q.push_back(make_pair(next_x, next_y));
			}
		}
	}

	return n * m - (3 + wall + virus + add_virus);    //빈칸수=전체-(3개(추가벽) + 기존벽 + 초기바이러스+퍼진바이러스)
}
int main(void)
{
	int input, result = 0;   //남은공간의 최소값이 0이라서 초기로 설정
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &input);
			arr[i][j] = input;
			if (input == 0) way.push_back(make_pair(i, j)); //벽이 없는 빈공간만 따로 설정
			if (input == 1) wall++;
			if (input == 2) virus++;
		}
	}
	//벽 3개를 모든 경우에 넣기.  --> 앞에서 벽이 없는 빈공간만 따로 설정하는것이 필요.--> 아주 기발한 생각
	for (int i = 0; i < way.size(); i++)
	{
		for (int j = i + 1; j < way.size(); j++)
		{
			for (int k = j + 1; k < way.size(); k++)
			{
				//0인 부분만 모든경우를 나눠서 벽세우기
				arr[way[i].first][way[i].second] = 1;
				arr[way[j].first][way[j].second] = 1;
				arr[way[k].first][way[k].second] = 1;

				result = max(result, BFS());  //모든 경우를 돌면서 최대값을 result에 대입

				//세운벽 초기화
				arr[way[i].first][way[i].second] = 0;
				arr[way[j].first][way[j].second] = 0;
				arr[way[k].first][way[k].second] = 0;
			}
		}
	}
	printf("%d", result);
	return 0;
}