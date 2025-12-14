#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(void) {
	const int INF = 1e9;
	int N;
	vector<vector<int>> cost;
	vector<int> dp;
	cin >> N;
	
	cost.resize(N, vector<int>(N));
	dp.assign(1<<N, INF);
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> cost[i][j];
		}
	}
	
	dp[0]=0;
	for(int mask=0; mask<(1<<N); mask++) {
		int depth = __builtin_popcount(mask);
		for(int j=0; j<N; j++) {
			if(mask & (1<<j)) continue;
			int next = (1<<j) | mask;
			dp[next] = min(dp[next], dp[mask] + cost[depth][j]);
		}
	}
	
	cout << dp[(1<<N) - 1];
	
	return 0;
}
