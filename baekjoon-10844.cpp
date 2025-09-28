#include <iostream>

using namespace std;

int dp[101][10]={0,};


int main(void) {
	int n, result=0;
	cin >> n;
	
	for(int i=1; i<10; i++) dp[1][i]=1;
	
	for(int i=2; i<=n; i++) {
		dp[i][0]=dp[i-1][1]%1000000000;
		for(int j=1; j<=8; j++) {
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
			dp[i][j]%=1000000000;
		}
		dp[i][9]=dp[i-1][8]%1000000000;
	}
	
	for(int i=0; i<10; i++) {
		result+= dp[n][i];
		result%=1000000000;
	}
	
	cout << result << endl;
}
