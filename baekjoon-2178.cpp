#include <iostream>
#include <queue>

using namespace std;

	queue<pair<int,int>> root;
	int n, m;
	//int maze[n][m];
	//bool visited[n][m];
	int maze[101][101];

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		string temp;
		cin >> temp;
		for(int j=0; j<m; j++) {
			maze[i][j]=temp[j]-'0';
			//visited[i][j]=false;
		}
	}
	
	root.push(make_pair(0,0));
	//visited[0][0]=true;
		
	int x[4]={1,0,-1,0}, y[4]={0,1,0,-1}, loc_x, loc_y;
	while(root.size()>0) {
		loc_x=root.front().second;
		loc_y=root.front().first;
		//visited[loc_y][loc_x]=true;
		//cout << loc_x << ", " << loc_y << "\n";
		
		if(loc_x==m-1&&loc_y==n-1) {
			//cout << "exit?\n";
			break;
		}
		
		for(int i=0; i<4; i++) {
			if(loc_x+x[i]>=0 && loc_x+x[i]<m && loc_y+y[i]>=0 && loc_y+y[i]<n) {
				if(maze[loc_y+y[i]][loc_x+x[i]]==1) {
					root.push(make_pair(loc_y+y[i],loc_x+x[i]));
					maze[loc_y+y[i]][loc_x+x[i]]=maze[loc_y][loc_x]+1;
				}
			}
		}
		root.pop();
		//root.shrink_to_fit();
	}
	
	cout << maze[n-1][m-1];
	
	return 0;
}
