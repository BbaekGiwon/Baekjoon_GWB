#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	
	vector<int> coin(n);
	
	for(int i=0; i<n; i++) {
		cin >> coin[i];
	}
	
	vector<int> dp(k+1, 10001);
	dp[0]=0;
	
	for(int i=0; i<k; i++) {
		for(int j=0; j<n; j++) {
			if(i+coin[j] <= k) {
				dp[i+coin[j]] = min(dp[i]+1, dp[i+coin[j]]);
			}
		}
	}
	
	if(dp[k] > 10000) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}
	
	
	return 0;
}
