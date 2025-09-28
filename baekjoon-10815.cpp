#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[20000001] = {0,};

int main(void) {
	int n, m;
	vector<int> sangeun;
	vector<int> ehey;
	
	cin >> n;
	for(int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		dp[temp+10000000]++;
	}
	
	cin >> m;
	for(int i=0; i<m; i++) {
		int temp;
		cin >> temp;
		if(dp[temp+10000000]>0) {
			ehey.push_back(1);
		}
		else {
			ehey.push_back(0);
		}
		
	}
	
	for(int i=0; i<m; i++) {
		cout << ehey[i] << " ";
	}
}
