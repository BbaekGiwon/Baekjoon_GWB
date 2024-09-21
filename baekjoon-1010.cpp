#include <iostream>

using namespace std;

int dp[31][16]={0,};

int binomial(int n, int k) {
	if(k==0||k==n) return dp[n][k] = 1;
	else if(dp[n][k]!=0) return dp[n][k];
	else return dp[n][k] = (binomial(n-1,k-1) + binomial(n-1,k));
}

int main(void) {
	int t, n, m;
	
	cin >> t;
	for(int i=0; i<t; i++) {
		cin >> n >> m;
		n = min(n,m-n);
		cout << binomial(m,n) << endl;
	}
}

