//Baekjoon 1260 DFS and BFS
//Not solved, copied

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int v, e, startNum;
vector<int> vec[1001];   // 인접리스트
bool check[1001];        // check배열
void dfs(int x);
void bfs(int x);

int main()
{
    /*정점의 개수, 간선의 개수, 탐색시작 정점의 번호 입력받기*/
    cin >> v >> e >> startNum;

    /*입력을 받아 인접리스트 만들기*/
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        // 주어진 간선이 양방향이라고 하였으므로
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    /*작은 번호의 노드부터 방문할 수 있도록 인접리스트를 정렬해줘야함*/
    for (int i = 1; i <= v; i++)
        sort(vec[i].begin(), vec[i].end());

    /*인접리스트를 이용해서 DFS, BFS탐색하기*/
    dfs(startNum);
    cout << "\n";

    memset(check, false, sizeof(check));

    bfs(startNum);
    cout << "\n";
}

void dfs(int x) {
    cout << x << " ";
    check[x] = true;

    for (int i = 0; i < vec[x].size(); i++) {
        int y = vec[x][i];
        if (check[y] == false)
            dfs(y);
    }
}

void bfs(int x) {
    queue<int> q;

    q.push(x);
    check[x] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        for (int i = 0; i < vec[currentNode].size(); i++) {
            int y = vec[currentNode][i];
            if (check[y] == false) {
                q.push(y);
                check[y] = true;
            }
        }
    }
}