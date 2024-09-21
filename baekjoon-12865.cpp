#include <iostream>

using namespace std;

int main(void) {
	int n, k, MAX=0;
	cin >> n >> k;
	int v[n+1], w[n+1], dp[n+1][k+1];
	for(int i=0; i<=k; i++) {
		dp[0][i]=0;
	}
	
	for(int i=1; i<=n; i++) {
		cin >> w[i] >> v[i];		
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=k; j++) {
			dp[i][j] = dp[i-1][j];
			if(j>= w[i]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
				MAX = max(MAX, dp[i][j]);
			}
		}
	}
	
	cout << MAX;
	
	
	return 0;
}
