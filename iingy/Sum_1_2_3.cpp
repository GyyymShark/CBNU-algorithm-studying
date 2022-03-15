#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int d[12]={0,1,2,4,7};

int main() {
	int n,i=0, number;
	scanf("%d", &n);
	while (i!=12) {
		for (i = 5; i < 12; i++) {
			d[i] = d[i - 3] + d[i - 2] + d[i - 1];
		}
		
	}	
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &number);
		printf("%d\n", d[number]);
	}

	return 0;
}

