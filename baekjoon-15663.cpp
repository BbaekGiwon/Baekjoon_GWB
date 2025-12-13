#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> num;
vector<int> path;
vector<bool> used;

void dfs(int depth) {
	if(depth == M) {
		for(int i=0; i<M; i++) {
			cout << path[i] << (i+1 == M ? "\n" : " ");
		}
		return;
	}
	
	int prev = -1; // 한 depth에서 같은 값은 한 번만 
	for(int i=0; i<N; i++) {
		if(used[i]) continue;
		if(num[i] == prev)  continue;
		
		used[i] = true;
		path.push_back(num[i]);
		prev = num[i];
		
		dfs(depth+1);
		
		path.pop_back();
		used[i] = false;
		
	}
}

int main(void) {
	cin >> N >> M;
	
	num.resize(N);
	used.assign(N, false);
	
	for(int i=0; i<N; i++) cin >> num[i];
	
	sort(num.begin(), num.end());
	
	dfs(0);	
	return 0;
}
