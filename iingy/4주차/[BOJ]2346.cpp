#include <iostream>
#include <list>
#include <vector>
using namespace std;
vector<int> arr;

int main() {
	int temp, N, v = 0, c = 0;

	list<int> li;
	list<int>::iterator it;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		li.push_back(temp);
		arr.push_back(i);
	}
	it = li.begin();
	while (1) {
		if (li.empty()) break;
		temp = *it;
		li.erase(it);
		c++;
		arr[v] = c;
		
		if (temp > 0) {
			for (int i = 0; i < temp-1; i++) {
				if (it == li.end()) {
					it = li.begin();
					v++;
				}
				else {
					it++;
					v++;
				}
			}
			v++;
		}
		else {
			for (int i = 0; i < temp - 1; i++) {
				if (it == li.end()) {
					it = li.begin();
					v++;
				}
				else {
					it++;
					v++;
				}
			}
			v--;
		}
	}


		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}

}