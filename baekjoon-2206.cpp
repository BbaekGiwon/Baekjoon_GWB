#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int y, x, broken, dist;
};

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for(int i=0; i<N; i++) {
        cin >> grid[i];
    }

    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));

    queue<Node> q;
    q.push({0,0,0,1});
    visited[0][0][0] = true;

    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};

    while(!q.empty()) {
        Node cur = q.front();
        q.pop();

        if(cur.y==N-1 && cur.x==M-1) {
            cout << cur.dist << "\n";
            return 0;
        }

        for(int i=0; i<4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
            
            // empty space
            if(grid[ny][nx] == '0' && !visited[ny][nx][cur.broken]) {
                visited[ny][nx][cur.broken] = true;
                q.push({ny, nx, cur.broken, cur.dist+1});
            }

            // wall
            if(grid[ny][nx] == '1' && cur.broken==0 && !visited[ny][nx][1]) {
                visited[ny][nx][1] = true;
                q.push({ny, nx, 1, cur.dist+1});
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}