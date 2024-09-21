#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main(void) {
	 ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	cin >> n;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		if(max_heap.size() > min_heap.size()) {
			min_heap.push(temp);
		} else {
			max_heap.push(temp);
		}
		
		if (!min_heap.empty() && !max_heap.empty() && min_heap.top() < max_heap.top()) {
			int max_top = max_heap.top();
			int min_top = min_heap.top();
			max_heap.pop();
			min_heap.pop();
			max_heap.push(min_top);
			min_heap.push(max_top);
		}
		
		cout << max_heap.top() << "\n";
	}	
}
