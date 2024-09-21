#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

//int imp[10]={0,};

int main(void) {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int n, m, cnt=0;
		cin >> n >> m;
		queue<int> que;
		vector<int> v;
		for(int i=0; i<n; i++) {
			int temp;
			cin >> temp;
			que.push(temp);
			v.push_back(temp);
		}
		sort(v.begin(),v.end(),compare);
		
		int a=0;
		while(1) {
			if(v[a]==que.front()) {
				if(m==0) break;
				que.pop();
				a++; m--;
			}
			else {
				que.push(que.front());
				que.pop();
				m--;
			}
			if(m<0) m=que.size()-1;
		}
		
		cout << a+1 << "\n";
	}
	
	
	
	
	
	return 0;
}
