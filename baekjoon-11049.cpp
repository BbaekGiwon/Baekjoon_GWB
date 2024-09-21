#include <iostream>
#include <limits>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int r[n][2];
	int dp[n][n];
	for(int i=0; i<n; i++) {
		cin >> r[i][0] >> r[i][1];
	}
	
	for(int i=0; i<n; i++) {
		dp[i][i]=0;
	}
	
	for(int i=0; i<n; i++) {
		for(int j=i-1; j>=0; j--) {
			dp[j][i]=numeric_limits<int>::max();
			for(int k=j; k<=i-1; k++) {
				dp[j][i] = min(dp[j][i], dp[j][k]+dp[k+1][i]+r[j][0]*r[k][1]*r[i][1]);
			}
		}
	}
	
	cout << dp[0][n-1];
	
	
	return 0;
}
