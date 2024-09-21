#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct subset {
	int rank=0;
	int parent;
}subset;

int find(subset *vertex, int i) {
	if(i==vertex[i].parent) return i;
	
	int temp=i;
	while(temp!=vertex[temp].parent) {
		temp=vertex[temp].parent;
	}
	return vertex[i].parent=temp;
}

void uni(subset *vertex, int a, int b) {
	int p_a=find(vertex,a), p_b=find(vertex,b);
	if(p_a==p_b) return;
	else {
		if(vertex[p_a].rank>=vertex[p_b].rank) {
			vertex[p_b].parent=p_a;
			if(vertex[p_a].rank==vertex[p_b].rank) {
				vertex[p_a].rank++;
			}
		}
		else {
			vertex[p_a].parent=p_b;
		}
	}
	
	
}

int main(void) {
	int v, e, result=0;
	cin >> v >> e;
	subset vertex[v+1];
	for(int i=1; i<=v; i++) {
		vertex[i].parent=i;
	}
	vector<pair<int, pair<int,int>>> edge;
	
	for(int i=0; i<e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({c,{a,b}});
	}
	
	sort(edge.begin(), edge.end());
	
	for(int i=0; i<edge.size(); i++) {
		int from=edge[i].second.first, to=edge[i].second.second;
		if(find(vertex,from)==find(vertex,to)) {
			continue;
		}
		
		uni(vertex, from, to);
		result+=edge[i].first;
	}
	
	cout << result;
	
	return 0;
}
