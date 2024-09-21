#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
	queue<int> que;
	vector<int> v;
	int n, k;
	cin >> n >> k;
	
	for(int i=1; i<=n; i++) {
		que.push(i);
	}
	
	while(que.size()!=0) {
		for(int i=0; i<k-1; i++) {
			que.push(que.front());
			que.pop();
		}
		v.push_back(que.front());
		que.pop();
	}
	
	cout << "<" << v.front();
	for(int i=1; i<n; i++) {
		cout << ", " << v[i];
	}
	cout << ">";
}
