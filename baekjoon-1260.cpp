#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int cnt=1;

vector <int> dfs_vis, bfs_vis;

void bfs(int *visited, vector<int>*edge, int r) {
	deque<int> visit_seq;
	
	bfs_vis.push_back(r);
	visited[r]=cnt++;
	visit_seq.push_back(r);

	while(visit_seq.size()>0) {
		int dest = visit_seq.front();
		visit_seq.pop_front();
		for(int i=0; i<edge[dest].size(); i++) {
			if(visited[edge[dest][i]]==0) {
				visited[edge[dest][i]]=cnt++;
				visit_seq.push_back(edge[dest][i]);
				bfs_vis.push_back(edge[dest][i]);
				//cout << edge[dest][i] << " is pushed!\n";
			}	
		}
	}		
}

void dfs(int *visited, vector<int> *graph, int r) {
	if(visited[r]>=1) return;
	
	dfs_vis.push_back(r);
	visited[r]=cnt++;
	
	for(int i=0; i<graph[r].size(); i++) {
		dfs(visited, graph, graph[r][i]);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	int n, m , r;
	cin >> n >> m >> r;
	
	int visited_dfs[n+1];
	int visited_bfs[n+1];
	for(int i=1; i<=n; i++) {
		visited_dfs[i]=0;
		visited_bfs[i]=0;
	}
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
	
	bfs(visited_bfs, edge, r);
	dfs(visited_dfs, edge, r);
	
	for(int i=0; i<dfs_vis.size(); i++) {
		cout << dfs_vis[i] << " ";
	}
	cout <<"\n";
	for(int i=0; i<bfs_vis.size(); i++) {
		cout << bfs_vis[i] << " ";
	}
		
	return 0;
}
