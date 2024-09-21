#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int n, cnt=1;

void bfs(int *visited, vector<int>*edge, int r) {
	deque<int> visit_seq;
	
	for(int i=1; i<=n; i++) {
		visited[i]=0;
	}
	visited[r]=cnt;
	visit_seq.push_back(r);

	while(visit_seq.size()>0) {
		int dest = visit_seq.front();
		visit_seq.pop_front();
		for(int i=0; i<edge[dest].size(); i++) {
			if(visited[edge[dest][i]]==0) {
				visited[edge[dest][i]]=cnt++;
				visit_seq.push_back(edge[dest][i]);
				//cout << edge[dest][i] << " is pushed!\n";
			}	
		}
	}		
}

int main(void) {
	int m , r=1;
	cin >> n >> m;
	
	int visited[n+1];
	vector<int> edge[n+1];
	
	for(int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	for(int i=1; i<=n; i++) {
		sort(edge[i].begin(), edge[i].end());
	}
	
	bfs(visited, edge, r);
	
	cout << cnt-1;
		
	return 0;
}
