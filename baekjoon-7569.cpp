#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main(void) {
	queue<tuple<int,int,int>> root;
	int m, n, h;
	cin >> m >> n >> h;
	int box[h][n][m];
	for(int k=0; k<h; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin >> box[k][i][j];
				if(box[k][i][j]==1) root.push(make_tuple(k,i,j));
			}
		}	
	}
	
	
	int loc_x, loc_y, loc_z;
	int x[6]={1,0,-1,0,0,0}, y[6]={0,1,0,-1,0,0}, z[6]={0,0,0,0,1,-1};
	while(!root.empty()) {
		auto f_q = root.front();
		loc_x=get<2>(f_q);
		loc_y=get<1>(f_q);
		loc_z=get<0>(f_q);
		
		for(int i=0; i<6; i++) {
			if(loc_x+x[i]>=0 && loc_x+x[i]<m && loc_y+y[i]>=0 && loc_y+y[i]<n && loc_z+z[i]>=0 && loc_z+z[i]<h) {
				if(box[loc_z+z[i]][loc_y+y[i]][loc_x+x[i]]==0) {
					root.push(make_tuple(loc_z+z[i],loc_y+y[i],loc_x+x[i]));
					box[loc_z+z[i]][loc_y+y[i]][loc_x+x[i]]=box[loc_z][loc_y][loc_x]+1;
				}
			}
		}
		
		/*for debug
		cout << "------------------\n";
		for(int k=0; k<h; k++) {
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					cout << box[k][i][j];
				}
				cout << "\n";
			}
		}
		cout << "------------------\n";
		*/
		root.pop();
	}
	
	int max_day=0;
	for(int k=0; k<h; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(box[k][i][j]==0) {
					cout << -1;
					return 0;
				}
				max_day=max(max_day,box[k][i][j]);
			}
		}	
	}
	
	
	cout << max_day-1;
	
	
	return 0;
}
