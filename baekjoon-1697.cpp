#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

int  time[100001];

int main(void) {
	queue<int> root;
	int n, k, loc=0, int_max=numeric_limits<int>::max();
	cin >> n >> k;
	loc=n;
	
	fill(time, time+100001, int_max);
	time[n]=0;
	root.push(n);
	
	while(!root.empty()) {
		//time[root.front()]=min(time[root.front()],time[loc]+1);
		loc=root.front();
		if(loc==k) {
			break;
		}
		root.pop();
		
		if(loc-1>=0&&time[loc-1]==int_max) {
			root.push(loc-1);
			time[loc-1]=min(time[loc-1], time[loc]+1);
		}
		if(loc+1<=100000&&time[loc+1]==int_max) {
			root.push(loc+1);
			time[loc+1]=min(time[loc+1], time[loc]+1);
		}
		if(loc*2<=100000&&time[loc*2]==int_max) {
			root.push(loc*2);
			time[loc*2]=min(time[loc*2], time[loc]+1);
		}
		
	}
	
	cout << time[k];
	
	return 0;
}
