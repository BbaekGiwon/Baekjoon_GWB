#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<pair<int,int>> root;
	int m, n;
	cin >> m >> n;
	int box[n][m];
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> box[i][j];
			if(box[i][j]==1) root.push(make_pair(i,j));
		}
	}
	
	int loc_x, loc_y, x[4]={1,0,-1,0}, y[4]={0,1,0,-1};
	while(!root.empty()) {
		loc_x=root.front().second;
		loc_y=root.front().first;
		
		for(int i=0; i<4; i++) {
			if(loc_x+x[i]>=0 && loc_x+x[i]<m && loc_y+y[i]>=0 && loc_y+y[i]<n) {
				if(box[loc_y+y[i]][loc_x+x[i]]==0) {
					root.push(make_pair(loc_y+y[i],loc_x+x[i]));
					box[loc_y+y[i]][loc_x+x[i]]=box[loc_y][loc_x]+1;
				}
			}
		}
		
		root.pop();
	}
	
	int max_day=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(box[i][j]==0) {
				cout << -1;
				return 0;
			}
			max_day=max(max_day,box[i][j]);
		}
	}
	
	cout << max_day-1;
	
	
	return 0;
}
