#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt=1;

void dfs(int r, int *visited, vector<int> *graph) {
	if(visited[r]>=1) return;
	
	visited[r]=cnt++;
	
	for(int i=0; i<graph[r].size(); i++) {
		dfs(graph[r][i], visited, graph);
	}
}

int main(void) {
	//시간줄이는거임 안중요 
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	
	int n, m, r;
	cin >> n >> m >> r;
	
	int visited[n+1];
	for(int i=0; i<=n; i++) visited[i]=0;
	vector<int> graph[n+1];
	
	for(int i=0; i<m; i++) {
		int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	for(int i=0; i<=n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	dfs(r, visited, graph);
	
	for(int i=1; i<=n; i++) cout << visited[i] << "\n";
	
	return 0;
}
