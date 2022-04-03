#include <iostream>
#define MAX 22
using namespace std;

int arr[MAX];
int store[MAX];
bool visited[MAX];

int Count = 0;


void dfs(int cur,int len, int n,int s,int curidx) {
	if (cur == len) {
		int sum = 0;
		for (int i = 0; i < len; i++) {
			//cout << store[i] << " ";
			sum += store[i];
		}
		if (sum == s)
			Count++;
		//cout << endl;
		return;
	}

	else {
		for (int i = 0; i < n; i++) {
			if (!visited[i] && i>=curidx) {
				visited[i] = true;
				store[cur] = arr[i];
				dfs(cur+1, len, n, s,i);
				visited[i] = false;
			}
		}
	}
}

void initialize(int n) {
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
}

int main() {
	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		initialize(n);
		dfs(0, i, n, s,0);
	}

	cout << "Count=" << Count;


	return 0;
}