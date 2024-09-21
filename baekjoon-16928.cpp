#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, m, dp[101];
int tunnel[101];
deque<int> root;

int main(void) {
	cin >> n >> m;
	
	for(int i=0; i<=100; i++) {
		tunnel[i]=0;
		dp[i]=200;
	}
	
	for(int i=0; i<n+m; i++) {
		int x, y;
		cin >> x >> y;
		tunnel[x]=y;
	}	
	
	root.push_back(1);
	dp[1]=0;
	
	while(!root.empty()) {
		int loc=root[0];
		
		root.pop_front();
		
		if(tunnel[loc]!=0) {
			dp[loc]=min(dp[loc], dp[tunnel[loc]]);
			root.push_front(tunnel[loc]);
			continue;
		}
		
		for(int i=1; i<=6; i++) {
			if(loc+i>=100) {
				dp[100]=min(dp[100], dp[loc]+1);
				break;
			}
			else if(tunnel[loc+i]!=0) {
				if(tunnel[tunnel[loc+i]]!=0) {
					root.push_front(tunnel[loc+i]);
				}
				else {
					root.push_back(tunnel[loc+i]);
				}
				dp[tunnel[loc+i]]=min(dp[dp[tunnel[loc+i]]],dp[loc]+1);
			}
			else {
				dp[loc+i]=min(dp[loc+i], dp[loc]+1);
				root.push_back(loc+i);
			}
		}
	}
	cout << dp[100];
	
	return 0;
}
