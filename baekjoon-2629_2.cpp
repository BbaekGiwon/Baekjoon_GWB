#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, m, max_w=0;
	
	cin >> n;
	vector<int> chu(n);
	for(int i=0; i<n; i++) {
		cin >> chu[i];
		max_w += chu[i];
	}
	
	
	cin >> m;
	vector<int> gu(m);
	for(int i=0; i<m; i++) {
		cin >> gu[i];
	}
	
	vector<vector<bool>> dp(n+1, vector<bool>(max_w+1, false));
	dp[0][0] = true;
	for(int i=1; i<=n; i++) {
		for(int w=0; w<=max_w; w++) {
			if(dp[i-1][w]) {
				dp[i][w]=true;
				if (w + chu[i - 1] <= max_w) {
                    dp[i][w + chu[i-1]] = true; // 왼쪽 저울에 올리는 경우
                }
                dp[i][abs(w - chu[i-1])] = true; // 오른쪽 저울에 올리는 경우
			}
		}
	}
	
	for(int i=0; i<m; i++) {
		if(dp[n][gu[i]]) cout << "Y ";
		else cout << "N ";
	}	
	return 0;
}
