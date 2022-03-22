#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int num;   //시도할 횟수
    cin >> num;

    vector<int> save(num);

    for (int i = 0; i < num; i++) {  //반복
        int n;
        cin >> n;  //n 입력 받음

        int* arr = new int[n+1];  //원래 여기서도 벡터를 사용했는데 그러면 반복하면서 문제가 생기는 것 같아서 동적할당, 해제를 쓰기로했다.
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;

        for (int i = 4; i <= n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        }

        save[i] = arr[n];  //한 번 돌고 출력이 아니라 마지막에 한번에 출력이길래 동적할당 해제 전에 save에 값을 담아뒀다.
        delete[] arr;
    }

    for (int j = 0; j < num; j++) {
        cout << save[j] << endl;
    }
    return 0;
}


