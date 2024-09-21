#include <iostream>

using namespace std;

int v[101];
int w[101];
int dp[101][10001];

int main(void) {
	int n, m, price=0, result=1000000000;
	cin >> n >> m;
	
	
	for(int i=1; i<=n; i++) {
		cin >> w[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> v[i];
		price+=v[i];
	}
	

	for(int i=1; i<=n; i++) {
		for(int j=0; j<=price; j++) {
			dp[i][j] = dp[i-1][j];
			if(j>= v[i]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]]+w[i]);
				if(dp[i][j] >= m) result = min(result,j);
				//MAX = max(MAX, dp[i][j]);
			}
		}
	}
	
	
	
	//cout << dp[4][35] << " " << v[5] << " " << dp[5][75] << "\n";
	
	cout << result;
	
	
	return 0;
}
