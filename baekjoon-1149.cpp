#include <iostream>

using namespace std;

int dp[1001][3]= {0,};

int main(void) {
	int n, min_value=1000000;
	
	cin >> n;
	int rgb[n+1][3]={0,};
	for(int i=1; i<=n; i++) {
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}
	
	for(int i=1; i<=n; i++) {
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgb[i][1];
		dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + rgb[i][2];
	}
	
	for(int i=0; i<3; i++) {
		min_value = min(dp[n][i], min_value);
	}
	
	cout << min_value << endl;
	
}
