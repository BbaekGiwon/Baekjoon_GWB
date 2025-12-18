#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main(void) {
	int N, M;
	vector<vector<char>> map;
	vector<vector<bool>> visited;
	queue<pair<int, int>> q;
	
	cin >> N >> M;
	
	map.resize(N, vector<char>(M));
	visited.resize(N, vector<bool>(M));
	
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin >> map[i][j];
			if(map[i][j] == 'I') {
				q.push({i,j});
				visited[i][j] = true;
			}
		}
	}
	
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int cnt = 0;
	while(!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		
		if(map[x][y] == 'P') cnt++;
		
		for(int i=0; i<4; i++) {
			int next_x = x+dx[i];
			int next_y = y+dy[i];
			if(0 <= next_x && next_x < N && 0 <= next_y && next_y < M) {
				if(visited[next_x][next_y]) continue;
				if(map[next_x][next_y] == 'X') continue;
				
				q.push({next_x, next_y});
				visited[next_x][next_y] = true;
			}
		}
	}
	
	if(cnt == 0) cout << "TT";
	else cout << cnt;	
	
	return 0;
}
