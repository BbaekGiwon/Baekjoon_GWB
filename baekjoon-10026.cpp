#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

static inline bool sameNormal(char a, char b) {
    return a == b;
}

static inline bool sameColorBlind(char a, char b) {
    // R과 G를 동일 취급
    if (a == 'B' || b == 'B') return a == b;
    return true; // (R,G) 조합이면 모두 같은 색
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	vector<vector<char>> input(N, vector<char>(N));
	
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> input[i][j];
		}
	}
	
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	for(int colorBlind=0; colorBlind<2; colorBlind++) {	
		vector<vector<bool>> vis(N, vector<bool>(N, false));	
		int ans = 0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(vis[i][j]) continue;
				
				ans++;
				
				queue<pair<int,int>> q;
				q.push({i,j});
				vis[i][j] = true;
				while(!q.empty()) {
					auto cur = q.front();
					int cur_x = cur.first, cur_y = cur.second;
					q.pop();
					
					for(int k=0; k<4; k++) {
						int next_x = cur_x + dx[k], next_y = cur_y + dy[k];
						
						if(0<=next_x && next_x<N && 0<=next_y && next_y<N) {
							if(vis[next_x][next_y]) continue;
							
							bool ok = colorBlind ? sameColorBlind(input[cur_x][cur_y], input[next_x][next_y])
	                                             : sameNormal(input[cur_x][cur_y], input[next_x][next_y]);
	                        if (!ok) continue;
	
	                        vis[next_x][next_y] = 1;
	                        q.push({next_x, next_y});
							
						}
					}
				}
			}
		}
		
		cout << ans << " ";
	}
	

    
	
	return 0;
}
