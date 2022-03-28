#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {

	int num;
	cin >> num;
	int final;
	
	int count = 1;

	vector <pair<int, int>> room(num);
	
	for (int i = 0; i < num; i++) {
		cin >> room[i].first >> room[i].second;
	}

	sort(room.begin(), room.end(), compare);
	

	/*for (int i = 0; i < num; i++) {
		cout << room[i].first << room[i].second << endl;
	}  */  //정렬 확인용

	final = room[0].second;
	                                  //끝나는 시간을 기준으로 비교해야함!
	for (int i = 1; i < num; i++) {   //여기서 i=1부터인게 중요!!
		if (room[i].first >= final) {  
			final = room[i].second;
			count++;
		}
	}

	cout << count;

	return 0;
}
