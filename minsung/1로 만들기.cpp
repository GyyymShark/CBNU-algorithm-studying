#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;
int arr[1000000] = { 0, };

int main() {
    int n;
    cin >> n;
    

        arr[1] = 0;
        arr[2] = 1;
        arr[3] = 1;   // arr[3]이 2인줄 알았다.. 왜냐하면 3나누기 3하면 1인데 머리가 굳었나 0이라 생각을해서 arr[3]=2로 둬서 시간을 많이 썻다..
                      // 3까지는 설정해주고 그 이후 반복문을 돌며 케이스를 나눠서 최소값을 구해서 그 값으로 변경해준다!

        for (int i = 4; i <= n; i++) {
            if ((i % 2 == 0) && (i % 3 == 0)) {
                arr[i] = min({ arr[i / 3] + 1,arr[i / 2] + 1,arr[i - 1] + 1 });
            }

            else if (i % 2 == 0) {
                arr[i] = min(arr[i-1]+1,arr[i/2]+1);
            }

            else if (i % 3 == 0) {
                arr[i] = min(arr[i-1] + 1, arr[i/3] + 1);
            }

            else {
                arr[i] = arr[i - 1] + 1;
            }

        }

    cout << arr[n];

    return 0;
}

