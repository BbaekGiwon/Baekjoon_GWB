#include <iostream>

using namespace std;

int dp[302][2] = {0,};

int main(void) {
	int n;
	
	cin >> n;
	int stair[n+1]={0,};
	for(int i=1; i<=n; i++) {
		cin >> stair[i];
	}
	
	dp[1][0] = stair[1];
	dp[1][1] = stair[1];
	
	for(int i=2; i<=n; i++) {
		dp[i][0] = dp[i-1][1] + stair[i];
		dp[i][1] = max(dp[i-2][0], dp[i-2][1]) +stair[i];
	}
		
		cout << max(dp[n][0],dp[n][1]) << endl;	
}
