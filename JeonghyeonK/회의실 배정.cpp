#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int main() {

	//사람 수 입력받기
	int N;
	cin >> N;

	//회의 시작 시간, 끝나는 시간 담은 pair vector 선언하고 입력받기
	vector<pair<int, int>> array;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		array.push_back(pair<int, int>(end, start));
	}

	//오름차순 정렬 (회의 종료 시간이 빠른 순으로, 같을 경우 시작 시간이 빠른 순)
	sort(array.begin(), array.end());

	//회의가 끝나는 시간 변수
	int breaktime = array[0].first;

	//회의 개수 변수
	int conference = 1;

	//회의시간이 겹치지 않는 회의들 중 끝나는 시간이 빠른 것을 우선으로 골라서 갱신
	for (int i = 1; i < N; i++) {
		if (array[i].first >= breaktime) {
			if (array[i].second >= breaktime) {
				breaktime = array[i].first;
				conference++;
			}
		}
	}



	cout << conference;


	return 0;
}