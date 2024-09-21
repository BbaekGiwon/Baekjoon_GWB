#include <iostream>

using namespace std;

int dp[1001]={0,};

int main(void) {
	int n;
	cin >> n;
	
	dp[1]=1; dp[2]=3;
	
	for(int i=3; i<=n; i++) {
		dp[i] = dp[i-1]%10007 + dp[i-2]*2%10007;
	}
	
	cout << dp[n]%10007;
	
	return 0;
}
