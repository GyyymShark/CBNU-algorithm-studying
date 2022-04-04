#include <iostream>
#include <deque>
#include <utility>
#include <math.h>

// iteraor를 이용해서 비긴을 계속 바꿔주며 할려했는데 실패
// 안풀려서 찾아봤는데 설마 이렇게 풀까 싶었는데 그냥 옆으로 옮기는 식이었음
using namespace std;

int main() {
	
	int number;
	cin >> number;

	deque <pair<int,int>> q;
	
	
	for (int i = 1; i <= number; i++) {
		int number;
		cin >> number;
		q.push_back({ i,number }); 
	}

	//deque <pair<int, int>>::iterator iter = q.begin();

	while (!q.empty()) {
		auto cur = q.front();  //개꿀이네 이거 auto 쓰니 걍 통채로 저장됨
		cout << cur.first << " ";
		int num2 = cur.second;
		q.pop_front();

		if (num2 > 0) {
			num2--;  
			while (!num2 == 0) {
				q.push_back(q.front());
				q.pop_front();
				num2--;
			}
		}
		else {
			while (!num2 == 0) {
				q.push_front(q.back());
				q.pop_back();
				num2++;
			}
		}

	}


		/*if (q[t].second> 0) {	
			cout << q[t].first;
			k = q[t].second;
			if (k > q.size()) {
				k = k % q.size();
				q.erase(q[t]);
			}

		}

		else if(q[t].second < 0) {
			cout << q[t].first;
			k = q[t].second;
			if (abs(k) > q.size()) {
				k = k % q.size();
				q.pop_front();
			}

		}
		
		if (q.size() == 0)
			break;

	}*/

	return 0;
}