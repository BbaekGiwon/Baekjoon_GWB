#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<int> que;
	int n;
	cin >> n;
	
	if(n==1) {
		cout << "1";
		return 0;
	}
	
	for(int i=2; i<=n; i++) {
		que.push(i);
	}
	
	while(que.size()!=1) {
		que.push(que.front());
		que.pop();
		que.pop();
	}
	
	cout << que.back();
	
	return 0;
}
