#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, cnt=0, x[4]={-1,0,1,0}, y[4]={0,1,0,-1};
	vector<int> num_cnt;
	cin >> n;
	int danji[n][n], visited[n][n];
	for(int i=0;i<n; i++) {
		string temp;
		cin >> temp;
		for(int j=0; j<n; j++) {
			danji[i][j]=temp[j]-'0';
			visited[i][j]=0;
		}
	}
	
	//use bfs
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			deque<pair<int,int>> sch;
			if(danji[i][j]!=0 && visited[i][j]==0) {
				int temp_cnt=1;
				
				sch.push_back({i,j});
				visited[i][j]=1;
				cnt++;
				
				while(sch.size()>0) {
					int t_x, t_y;
					t_x=sch.front().first;
					t_y=sch.front().second;
					sch.pop_front();
					
					for(int k=0; k<4; k++) {
						if(t_x+x[k]>=0 && t_x+x[k]<n && t_y+y[k]>=0 &&t_y+y[k]<n) {
							if(danji[t_x+x[k]][t_y+y[k]]!=0 && visited[t_x+x[k]][t_y+y[k]]==0) {
								sch.push_back({t_x+x[k],t_y+y[k]});
								visited[t_x+x[k]][t_y+y[k]]=1;
								temp_cnt++;
							}
						}
					
					}
				}
				num_cnt.push_back(temp_cnt);
			}			
		}
	}
	
	sort(num_cnt.begin(), num_cnt.end());
	
	cout << cnt << "\n";
	for(int i=0; i<num_cnt.size(); i++) {
		cout << num_cnt[i] << "\n";
	}
	
	
	return 0;
}
