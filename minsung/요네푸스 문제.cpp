#include <iostream>
#include <queue>

using namespace std;

int main() {
	
	int number, interval;  
	cin >> number >> interval;      //크기와 간격 입력 받음

	queue <int> q;
	
	for (int i = 1; i <= number; i++) {
		q.push(i);
	}

	cout << "<";
	int locate = 1;
	while (1) {
		if (interval == locate) {   //찾는 위치인 경우
			if (q.size() == 1) {   //출력 형식 맞추기위해 마지막과 아닐 경우로 나눔
				cout << q.front();
				q.pop();
				locate = 1;
			}
			else {
				cout << q.front() << ", ";
				q.pop();
				locate = 1;
			}
		}

		else {   //찾는 위치가 아닌 경우
			int num = q.front();
			q.push(num);
			locate++;
			q.pop();
		}

		if (q.size() == 0)  //q의 사이즈가 0이면 반복문 탈출
			break;
	}

	cout << ">";

	return 0;
}