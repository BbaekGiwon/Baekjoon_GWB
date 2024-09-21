#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	deque<pair<int,int>> dq;
	deque<int> answer;
	for(int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		dq.push_back({i,temp});
	}
	
	while(!dq.empty()) {
		int move = dq[0].second;
		answer.push_back(dq[0].first+1);
		dq.pop_front();
		
		if(move>0) {
			for(int i=1; i<move; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			for(int i=0; i>move; i--) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
		
	}
	
	for(int i=0; i<n; i++) {
		cout << answer[i] << " ";
	}
}
