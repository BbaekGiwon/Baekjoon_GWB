#include <iostream>

using namespace std;

int dp[503][503]={0,};

int main(void) {
	int n;
	
	cin >> n;
	int input[n+1][n+1];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			cin >> input[i][j];
		}
	}
	
	for(int i=0; i<=n-1; i++) {
		for(int j=1; j<=n-i; j++) {
			dp[n-i][j] = max(dp[n-i+1][j], dp[n-i+1][j+1]) + input[n-i][j];
		}
	}
	
	cout << dp[1][1] << endl;
}
