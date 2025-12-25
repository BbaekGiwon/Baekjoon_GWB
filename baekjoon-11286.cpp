#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

struct cmp {
    bool operator()(int a, int b) const {
        int aa = abs(a), bb = abs(b);
        if (aa != bb) return aa > bb; // 절댓값 작은 게 top
        return a > b;                 // 절댓값 같으면 더 작은 수가 top
    }
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	priority_queue<int, vector<int>, cmp> pq;
	
	for(int i=0; i<N; i++) {
		int temp;
		cin >> temp;
		
		if(temp == 0) {
			if(pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(temp);
		}
	}
	
	
	
	return 0;
}
