#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int date 0; // how many date will cost -> result
int row, col; //row and col of lake
deque<pair<int, int>> dest;
// store location of swans
int first_swan[2] = {-1, -1}, second_swan[2] = {-1, -1};

bool is_next_to(char **array, int mode, int x, int y) {
	//used at bfs, is it possible to go?
	if(mode == 0) {
		
	}
	// used at melt, will it gonna be melt? 
	else if (mode == 1){
		
	}
	// wrong access
	else {
		exit(1);
	}
}

bool bfs(char**array, bool**visited) {
	int move_row[4] = {1, 0, -1, 0};
	int move_col[4] = {0, 1, 0, -1};
	
	while(!dest.empty()) {
		int cur_row = dest[0].first;
	    int cur_col = dest[0].second;
	    dest.pop_front();
	    visited[cur_row][cur_col] = true;
	    if(cur_row == second_swan[0] && cur_col == second_swan[1]) {
	    	return true;
		}
		
		for(int i=0; i<4; i++) {
			if(cur_row+move_row[i]<row && cur_row+move_row[i]>=0 && cur_col+move_col[i]<col && cur_col+move_col[i]) {
				if(array[cur_row+move_row[i]][cur_col+move_col[i]] == '.' && !visited[cur_row+move_row[i]][cur_col+move_col[i]]) {
					dest.push_back(pair<cur_row+move_row[i], cur_col+move_col[i]>);
				}
			}
		}
	}
	
	
	return false;
}

void melt(char**array) {
	int move_row[4] = {1, 0, -1, 0};
	int move_col[4] = {0, 1, 0, -1};
	
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			if(array[i][j] == 'X') {
				for(int k=0; k<4; k++) {
					if(array[i+move_row[k]][j+move_col[k]] == '.') {
						dest.push_back(pair<i+move_row[k], j+move_col[k]>);
						break;
					}
				}
			}
		}
	}
	
	for(const auto& [i, j] : dest) {
		array[i][j] = '.';
	}
}

int main(void) {
	cin >> row >> col;
	
	
	// lake
	char **array = new char*[rows];
	// visited location
	bool **visited = new bool*[rows];
	for (int i=0; i<rows; i++) {
		array[i] = new char[cols];
		visited[i] = new bool[cols];
	}
	
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			cin >> array[i][j];
			if(array[i][j]=='L') {
				if(first_swan[0]==-1) {
					first_swan[0]=i;
					first_Swan[1]=j;
				} else {
					secpnd_swan[0]=i;
					second+swan[1]=j;
				}
			}
		}
	}
	
	dest.push(pair<first_swan[0], first_swan[1]);
	while(!bfs(array, visited)) {
		date++;
		melt(array);
	}
	
	
	
	// print result
	cout << date;
	
	for (int i=0; i<rows; i++) {
		delete[] array[i];
	}
	delete[] array;

	return 0;
}
