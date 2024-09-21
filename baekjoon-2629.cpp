#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(void) {
	int n_chu, n_ball, w_sum=0;
	cin >> n_chu;
	int chu[n_chu+1];	
	for(int i=1; i<=n_chu; i++) {
		cin >> chu[i];
		w_sum+=chu[i];
	}
		
	cin >> n_ball;
	int ball[n_ball];
	for(int i=0; i<n_ball; i++) {
		cin >> ball[i];
	}
	//-----------------------------------
	bool dp[n_chu+1][w_sum+1];
	memset(dp, false, sizeof(dp));
	for(int i=0; i<=n_chu; i++) {
		dp[i][0]=true;
	}
	
	for(int i=1; i<=n_chu; i++) {
		for(int j=1; j<=w_sum; j++) {
			dp[i][j]=dp[i-1][j];
			if(chu[i]-j>=0) {
				//cout << "ahah\n";
				dp[i][chu[i]-j]=true;
				//if(dp[i][abs(j-chu[i])]) cout << i << " " << abs(j-chu[i]) << " ho\n";
			}
			if(dp[i][j] && j-chu[i]>=0) {
				dp[i][j-chu[i]]=true;
			}
			if(j>=chu[i]) {
				dp[i][j] = dp[i][j] | dp[i-1][j-chu[i]];
			}
		}
	}
	
	/*
	for(int j=1; j<=w_sum; j++) {
		dp[0][j]=dp[n_chu][j];
	}
	
	for(int i=1; i<=n_chu; i++) {
		for(int j=1; j<=w_sum; j++) {
			dp[i][j]=dp[i-1][j];
			if(j+chu[i]<=w_sum && dp[i-1][j+chu[i]]) {
				dp[i][j]=true;
			}
		}
	}//*/
	
	//* for debug
		for(int i=0; i<=n_chu; i++) {
			for(int j=0; j<=w_sum; j++) {
				//if(dp[i][j]) cout <<"1 ";
				//else cout << "0 ";
				if(dp[i][j]) cout << i << ", " << j << " : true\n";
			}
			cout << "\n";
		}//*/
	
	
	
	//------------------------------------
	for(int t=0; t<n_ball; t++) {
		if(ball[t]>w_sum) cout << "N ";
		else if(dp[n_chu][ball[t]]) cout << "Y ";
		else cout << "N ";
	}
	
	return 0;
}
