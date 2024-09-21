#include <iostream>

using namespace std;

int dp[100]={0,};

int main(void) {
	int n;
	cin >> n;
	int time[n+1]={0,}, pay[n+1]={0,};
	
	for(int i=1; i<=n; i++) {
		cin >> time[i] >> pay[i];
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			dp[j]=max(dp[j], dp[j-1]);
			if(j+time[j]-1<=n) {
				dp[j+time[j]]=max(dp[j+time[j]], dp[j]+pay[j]);
				j+=time[j]-1;
			}
		}
	}
	
	cout << max(dp[n], dp[n+1]);
	
}
