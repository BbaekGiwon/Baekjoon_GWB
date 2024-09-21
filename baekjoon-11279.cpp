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

        if (x == 0) {  // 가장 큰 값 출력하고 제거
            if (max_heap.empty()) cout << "0\n";
            else {
                cout << max_heap.top() << '\n';
                max_heap.pop();
            }
        }
        else max_heap.push(x);  // 자연수 x를 배열에 추가
    }

    return 0;
}

