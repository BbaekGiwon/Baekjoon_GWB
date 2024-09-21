#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		queue<pair<int,int>> root;
		int I, loc_x, loc_y, des_x, des_y;
		int x[8]={1,2,2,1,-1,-2,-2,-1}, y[8]={2,1,-1,-2,-2,-1,1,2};
		cin >> I;
		cin >> loc_y >> loc_x >> des_y >> des_x;
		int arr[I][I]={0,};
		memset(arr, 0, sizeof(arr));
		
		root.push(make_pair(loc_y,loc_x));
		arr[loc_y][loc_x]=1;
		
		
		while(1) {
			loc_y=root.front().first;
			loc_x=root.front().second;
			//cout << loc_y << ", " << loc_x << "\n";
			if(loc_y==des_y && loc_x==des_x) break;
			root.pop();
			
			for(int j=0; j<8; j++) {
				if(loc_x+x[j]>=0 && loc_x+x[j]<I && loc_y+y[j]>=0 && loc_y+y[j]<I) {
					if(arr[loc_y+y[j]][loc_x+x[j]]==0) {
						arr[loc_y+y[j]][loc_x+x[j]]=arr[loc_y][loc_x]+1;
						root.push(make_pair(loc_y+y[j], loc_x+x[j]));
					}
				}
			}
		}
		
		cout << arr[des_y][des_x]-1 << "\n";
	}
	
	
	
	return 0;
}
