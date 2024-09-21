#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void) {
	deque<int> dq;
	int n, m, cnt=0;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		dq.push_back(i);
	}
	
	for(int i=0; i<m; i++) {
		int temp;
		cin >> temp;
		if(find(dq.begin(),dq.end(),temp)-dq.begin()<=(dq.end()-dq.begin())/2) {
			while(dq.front()!=temp) {
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
		}
		else {
			while(dq.front()!=temp) {
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
		dq.pop_front();
	}
	
	cout << cnt;
	
	return 0;
}
