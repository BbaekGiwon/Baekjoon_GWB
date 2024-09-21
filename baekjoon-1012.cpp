#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int t, x[4]={-1,0,1,0}, y[4]={0,-1,0,1};
	cin >> t;
	
	for(int i=0; i<t; i++) {
		int cnt=0, n, m, k;
		vector<pair<int,int>> cabage;
		cin >> m >> n >> k;
		
		int farm[n][m], visited[n][m];
		for(int j=0; j<n; j++) {
			for(int l=0; l<m; l++) {
				farm[j][l]=0;
				visited[j][l]=0;
			}
		}
		for(int j=0; j<k; j++) {
			int t_x, t_y;
			cin >> t_x >> t_y;
			farm[t_y][t_x]=1;
			cabage.push_back(make_pair(t_y, t_x));
		}
		
		//cout << "\n";
		while(cabage.size()>0) {
			int loc_x=cabage[cabage.size()-1].second, loc_y=cabage[cabage.size()-1].first;
			if(visited[loc_y][loc_x]==0&&farm[loc_y][loc_x]!=0) {
				cnt++;
				//cout << loc_x << " "<< loc_y << "\n";
					
				vector<pair<int,int>> will_visit;
				will_visit.push_back(make_pair(loc_y,loc_x));
				while(will_visit.size()>0) {
					int b_flag=0;
					loc_x=will_visit[will_visit.size()-1].second;
					loc_y=will_visit[will_visit.size()-1].first;
					visited[loc_y][loc_x]=1;
					for(int j=0; j<4; j++) {
						if(visited[loc_y+y[j]][loc_x+x[j]]==0&&farm[loc_y][loc_x]!=0) {
							if(loc_y+y[j]>=0 && loc_y+y[j]<n && loc_x+x[j]>=0 && loc_x+x[j]<m) {
								will_visit.push_back(make_pair(loc_y+y[j],loc_x+x[j]));
								b_flag=1;
								break;
							}
							
						}
					}
					if(b_flag==1) continue;
					
					will_visit.pop_back();					
				}	
			}
			cabage.pop_back();			
		}
		cout << cnt << "\n";
	}
	
	
	
	
	
	return 0;
}
