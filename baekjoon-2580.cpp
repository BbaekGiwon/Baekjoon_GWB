#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int,int>> blank;

int sudoku[9][9];

bool find_end=false;

void find_val(int idx) {
	if(find_end) return;
	
	cout << "idx " << idx << "\n";
	
	int y=blank[idx].first;
	int x=blank[idx].second;
	int temp_val=1, pre_val=0;
	bool b_flag=false;
	bool visited[10];
	for(int i=0; i<=9; i++) visited[i]=false;
	
	while(temp_val<=9) {
		while(pre_val!=temp_val){
			pre_val=temp_val;
			//col
			for(int i=0; i<9; i++) {
				if(sudoku[y][i]==temp_val) {
					temp_val++;
				}
			}
			//row
			for(int i=0; i<9; i++) {
				if(sudoku[i][x]==temp_val) {
					temp_val++;
				}
			}
			//block
			for(int i=y-y%3; i<y-y%3+3; i++) {
				for(int j=x-x%3; j<x-x%3+3; j++) {
					if(sudoku[i][j]==temp_val) {
						temp_val++;
					}
				}
			}
			
			if(visited[temp_val]) temp_val++;
		}
		
				
		if(temp_val>9) {
			
			cout <<"ax\n";
			return;
		}
		else {
			sudoku[y][x]=temp_val;
			cout << "y " << y << " x " << x << " " <<sudoku[y][x] << "\n";
			if(idx==blank.size()-1) {
				find_end=true;
				return;	
			}
			else {
				find_val(idx+1);
				visited[temp_val]=true;
				temp_val=1;
			}
		}
	}

	
	
}

int main(void) {	
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			cin >> sudoku[i][j];
			if(sudoku[i][j]==0) blank.push_back({i,j});
		}
	}
	
	//cout << "blank " << blank.size() << "\n";
	
	find_val(0);
	
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}
	
	
	
	
	return 0;
}
