#include <iostream>

using namespace std;

int dp[1001] = {0,};

int main(void) {
	int n, result=0;
	cin >> n;
	int input[n+1]={0,};
	
	for(int i=1; i<=n; i++) {
		cin >> input[i];
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=0; j<i; j++) {
			if(input[i]>input[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	
	for(int i=1; i<=n; i++) result = max(result, dp[i]);
	
	cout << result << endl;
}
