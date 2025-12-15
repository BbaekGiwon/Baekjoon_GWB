#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int N;
int W[16][16];
int dp[16][1<<16];

int tsp(int u, int mask) {
	if(mask == (1<<N) - 1) { // 모든 도시 방문 완료 
		if(W[u][0] == 0) return INF;
		else return W[u][0]; 
	}
	
	int &ret = dp[u][mask]; // 이렇게 하면 더 간단함
	if(ret!=-1) return ret;
	
	ret = INF;
	
	// 다음 도시 이동
	for(int v=0; v<N; v++) {
		// visited 
		if(mask & (1<<v)) continue;
		// 길 없음
		if(W[u][v]==0) continue;
		
		ret = min(ret, tsp(v, mask | (1<<v)) + W[u][v]); 
	}
	return ret;
}


int main(void) {
	cin >> N;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> W[i][j];
		}
	}
	
	memset(dp, -1, sizeof(dp));
	
	int ans = tsp(0, 1<<0);
	
	cout << ans;
	
	return 0;
}
