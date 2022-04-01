#include <iostream>
#include <list>
using namespace std;

int main() {
	int N, K, C = 1;
	cin >> N >> K;
	list <int> li;
	list<int>::iterator it;
	for (int i = 1; i <= N; i++) {
		li.push_back(i);
	}
	it = li.begin();
	cout << "<";
	while (1) {
		if (it == li.end()) {
			it = li.begin();
		} //1,4 남을때 오류
		if (C == K) {
			cout << *it << ", ";
			it = li.erase(it);
			C = 1;
		}
		if (li.size() == 1) break;

		if (it == li.end()) {
			it = li.begin();
		}
		C++;
		it++;
	}
	cout << *li.begin()<<">";
}