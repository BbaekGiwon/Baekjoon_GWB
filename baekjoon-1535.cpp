#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int L[n+1], J[n+1], dp[n+1][100];
	for(int i=1; i<=n; i++) {
		cin >> L[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> J[i];
	}
	
	for(int i=0; i<=n; i++) {
		dp[i][0]=0;
	}
	for(int i=0; i<100; i++) {
		dp[0][i]=0;
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<100; j++) {
			dp[i][j]=dp[i-1][j];
			if(L[i]<=j) {
				dp[i][j]=max(dp[i][j], dp[i-1][j-L[i]]+J[i]);
			}
		}
	}
	/*for debug
	for(int i=0; i<=n; i++) {
		for(int j=0; j<100; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	cout << dp[n][99];
		
	return 0;
}
