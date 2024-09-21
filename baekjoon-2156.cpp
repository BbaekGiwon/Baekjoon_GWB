#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int dp[10001] = {0,};
int stair[10001]={0,};

int main(void) {
	int n;
	
	cin >> n;
	//int stair[n+1]={0,};
	for(int i=1; i<=n; i++) {
		cin >> stair[i];
	}
	

	
	dp[1]=stair[1];
	dp[2]=stair[1]+stair[2];
	dp[3]=max(dp[2], max(stair[1]+stair[3], stair[2]+stair[3]));
	
	for(int i=4; i<=n; i++) {
		dp[i] = max(max(dp[i-2]+stair[i], dp[i-1]) , dp[i-3]+stair[i-1]+stair[i]);
	}
		
	cout << max(dp[n], dp[n-1])<< endl;	
}
