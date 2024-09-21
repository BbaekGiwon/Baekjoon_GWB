#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n, m;
	deque<int> q;
	
	cin >> n;
	int *idx = new int[n] ;
	for(int i=0; i<n; i++) cin >> idx[i];
	
	for(int i=0; i<n; i++)  {
		int temp;
		cin >> temp;
		if(idx[i]==0) q.push_front(temp);
	}
	
	cin >> m;
	for(int i=0; i<m; i++) {
		int temp;
		cin >> temp;
		q.push_back(temp);
		cout << q.front() << " ";
		q.pop_front();
	}	
	
	return 0;
}
