#include<stdio.h>
#include<iostream>
#include<queue>

    using namespace std;

    int n; // ������ ������ �޾��� ����
    priority_queue<int> pq; // int�� �켱���� ť ����
    int main() {
        cin >> n;
        while (n--) { // ������ ������ŭ �ݺ�
            int x; // ���꿡 ���� ������ �޾��� ����
            cin >> x;
            if (x == 0) { //x�� 0�̶��
                if (pq.empty()) cout << "0\n";
                // queue�� ������� ��� 0 ���
                else {
                    cout << pq.top() << "\n";
                    pq.pop();
                    // ���� ���� ���ִ� ���� ���
                    // pop()�� ���ָ� queue�� FIFO ���� ������ ������ ���� ������ �ȴ�.
                }
            }
            else { // x�� 0�� �ƴ϶��
                pq.push(x); // �Է��� ���� queue�� ����
            }
        }
        return 0;
    }
