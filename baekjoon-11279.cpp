#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n;
    cin >> n;

    priority_queue<int> max_heap;
    while (n--) {
        int x;
        cin >> x;

        if (x == 0) {  // ���� ū �� ����ϰ� ����
            if (max_heap.empty()) cout << "0\n";
            else {
                cout << max_heap.top() << '\n';
                max_heap.pop();
            }
        }
        else max_heap.push(x);  // �ڿ��� x�� �迭�� �߰�
    }

    return 0;
}

