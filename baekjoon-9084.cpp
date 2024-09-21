#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int n, m;
		cin >> n;
		
		int coin[n+1];
		for(int j=1; j<=n; j++) {
			cin >> coin[j];
		}
		
		cin >> m;
		int dp[n+1][m+1];
		for(int j=0; j<=n; j++) {
			dp[j][0]=0;
		}
		for(int j=0; j<=m; j++) {
			dp[0][j]=0;
		}
		for(int j=coin[1]; j<=m; j+=coin[1]) {
			dp[1][j]=1;
		}
		
		for(int j=2; j<=n; j++) {
			for(int k=1; k<=m; k++) {
				dp[j][k]=dp[j-1][k];
				if(k>=coin[j]) {
					dp[j][k]=max(dp[j][k], dp[j-1][k]+1);
					dp[j][k]=max(dp[j][k], dp[j][k-coin[j]]+1);
				}
			}
		}
		
		cout << "\n";
		for(int j=0; j<=n; j++) {
			for(int k=0; k<=m; k++) {
				cout <<dp[j][k] << " ";
			}
			cout << "\n";
		}
		
		cout << "\n" << dp[n][m] << "\n\n";
	}
	
	
	
	return 0;
}
