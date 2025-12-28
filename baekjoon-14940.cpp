#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> input(n, vector<int>(m));
	vector<vector<int>> result(n, vector<int>(m, -1));
	queue<pair<int,int>> q;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> input[i][j];
			if(input[i][j] == 0) {
				result[i][j] = 0;
			}
			if(input[i][j] == 2) {
				q.push({i,j});
				result[i][j] = 0;
			}
		}
	}
	
	int d_x[4] = {1, 0, -1, 0};
	int d_y[4] = {0, 1, 0, -1};
	
	while(!q.empty()) {
		auto cur = q.front();
		q.pop();
		
		int cur_x = cur.first, cur_y = cur.second;
		for(int i=0; i<4; i++) {
			int next_x = cur_x + d_x[i];
			int next_y = cur_y + d_y[i];
			if(0<=next_x && next_x<n && 0<=next_y && next_y<m) {
				// 벽인 경우
				if(input[next_x][next_y] == 0) continue;
				
				// 방문한 경우 
				if(result[next_x][next_y] != -1) continue;
					
				result[next_x][next_y] = result[cur_x][cur_y] + 1;
				q.push({next_x, next_y});
			}
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}	
	
	return 0;
}
