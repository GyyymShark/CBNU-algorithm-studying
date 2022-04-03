/* 백준 1931 회의실 배정
   By Evergyu*/
#include <iostream>
using namespace std;
struct clas {
	int start;
	int end;
};

int main() {
	int N;
	cin >> N;
	clas* c = new clas[N+1];
	for (int i = 1; i <= N; i++) {
		cin >> c[N].start >> c[N].end;
	}

}