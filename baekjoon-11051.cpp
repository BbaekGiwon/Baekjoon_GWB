#include <iostream>

using namespace std;

int dp[10001][5001]={0,};

int binomial(int n, int k) {
	if(k==0||k==n) return dp[n][k] = 1;
	else if(dp[n][k]!=0) return dp[n][k];
	else return dp[n][k] = (binomial(n-1,k-1) + binomial(n-1,k))%10007;
}

int main(void) {
	int n, k;
	cin >> n >>k;
	k=min(k,n-k);
	cout << binomial(n, k) << endl;
}
