#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int n, ms_max=-1000;
		cin >> n;
		int arr[n], dp[n]={0,};
		for(int j=0; j<n; j++) {
			cin >> arr[j];
			ms_max=max(ms_max, arr[j]);
		}
		
		if(ms_max<0) cout << ms_max << endl;
		else {
			dp[0]=arr[0];
			for(int j=1; j<n; j++) {
				dp[j]=max(dp[j-1]+arr[j], 0);
			}
		
			for(int j=0; j<n; j++) {
				ms_max=max(ms_max, dp[j]);
			}
			cout << ms_max << endl;
		}
	}
	return 0;
}
