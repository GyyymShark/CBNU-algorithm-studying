#include <iostream>
#include <string>

using namespace std;


void hanoi(int n,int from, int by, int to) {
	if (n == 1) {
		cout << from << " " << to << "\n";//movedisk
	}
	else {
		hanoi(n - 1, from, to, by);	//원판 n-1개를 1에서 3을거쳐 2로 옮긴다
		cout << from << " " << to << "\n";//1개의 원판을 1에서 3으로 옮김
		hanoi(n - 1, by, from, to);	//2에 있는 원판 n-1개 3으로 옮겨줌
	}
}

int main() {

	int k;
	cin >> k;
	string answer;
	answer = to_string(pow(2, k));
	int idx = answer.find('.');
	answer = answer.substr(0, idx);
	answer[answer.length() - 1] -= 1;
	cout << answer;

	cout << answer<<"\n";
	if (k <= 20) {
		hanoi(k, 1, 2, 3);
	}


	return 0;
}


