#include <iostream>
#include <vector>   //벡터를 통해 연결리스트로 그래프를 생성
#include <queue>
#include <algorithm>
using namespace std;
vector<int> graph[1001];
int visited[1001];
void DFS(int v)
{
	visited[v] = 1; //방문을 하고
	cout << v << " ";
	for (int i = 0; i < graph[v].size(); i++)
	{
		if (!visited[graph[v][i]]) //해당 간선을 방문하지 않았다면
		{
			DFS(graph[v][i]);
		}
	}
}
queue<int> bfs;
int k;
void BFS(int v)
{
	visited[v] = 1;
	cout << v << " ";
	for (int i = 0; i < graph[v].size(); i++) {
		bfs.push(graph[v][i]);
		visited[graph[v][i]] = 1;
	}
	while (!bfs.empty())
	{
		k = bfs.front();
		cout << k << " ";
		bfs.pop();
		for (int i = 0; i < graph[k].size(); i++)
		{
			if (!visited[graph[k][i]])
			{
				bfs.push(graph[k][i]);
				visited[graph[k][i]] = 1;
			}
		}
	}
}
int main(void)
{
	int n, m, v;
	int start, end;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end;
		//양방향 간선이다.
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());   //오름차순이 되도록 정렬
	}
	DFS(v);
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		visited[i] = 0;
	}
	BFS(v);
	return 0;
}