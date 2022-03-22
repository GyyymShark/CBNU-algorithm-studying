/*
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200002
using namespace std;

bool visited[MAX];

bool cmp(pair<int, int> a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}

	return a.second < b.second;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int j = 0;
	int visitcount = 0;
	int count = 0;
	int n;
	cin >> n;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	sort(v.begin(), v.end(), cmp);




	while (true) {
		if (visitcount == n)
			break;

		int start = v[j].first;
		int end = v[j].second;
		visited[j] = true;
		visitcount++;
		count++;

		for (int i = 1; i < n; i++) {
			if (end == v[i].first && !visited[i]) {
				start = v[i].first;
				end = v[i].second;
				visited[i] = true;
				visitcount++;
			}
		}

		j++;
	}

	cout << count;

	return 0;
}
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;	//작은값이 우선순위가 된다

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}

	sort(v.begin(), v.end());
	pq.push(v[0].second);	//첫번째 수업 종료시간 pq에 삽입
	for (int i = 1; i < n; i++) {	//필요한 강의실 탐색
		pq.push(v[i].second);	//i번째 수업 종료시간 pq에 삽입

		if (pq.top() <= v[i].first) {
			pq.pop();
		}

	}
	cout << pq.size();
	return 0;
}