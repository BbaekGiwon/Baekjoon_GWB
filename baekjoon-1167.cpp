#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> dfs_farthest(int start, const vector<vector<pair<int, int>>>& adj) {
	int n = (int)adj.size()-1; // num of nodes
	vector<int> dist(n+1, -1);
	vector<int> st;
	st.push_back(start); dist[start]=0;
	
	//dfs
	while(!st.empty()) {
		int u=st.back(); 
		st.pop_back();
		for(const auto &e : adj[u]) {
			int v = e.first;
			int w = e.second;
			if(dist[v] == -1) {
				dist[v] = dist[u] + w;
				st.push_back(v);
			}
		}
	}
	
	int far = start;
	for(int i=1; i<=n; i++) if(dist[far] < dist[i]) far=i;
	return {far, dist[far]};	
}

int main(void) {
	int V;
	cin >> V;
	
	vector<vector<pair<int,int>>> cost(V+1);
	
	for(int i=0; i<V; i++) {
		int node;
		cin >> node;
		
		int dst, c;
		while(1) {
			cin >> dst;
			if(dst==-1) break;
			cin >> c;
			cost[node].push_back({dst,c});
		}
	}
	
	auto [u, _d] = dfs_farthest(1, cost);
	auto [v, diameter] = dfs_farthest(u, cost);
	
	cout << diameter;
	
	return 0;
}
