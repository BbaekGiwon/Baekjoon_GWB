#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<int> v;
int visited[9]={0,};
int arr[9]={0,};

void dfs(int cnt, int num) {
	if(cnt==m) {
		for(int i=0; i<m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int i=num; i<n; i++) {
		if(!visited[i]) {
			arr[cnt]=v[i];
			//visited[i]++;
			dfs(cnt+1, i);
			visited[i]=0;
		}
	}
}

int main(void) {
	
	cin >> n >> m;

	for(int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	sort(v.begin(),v.end());
	
	dfs(0,0);
	
	
	
	
	return 0;
}
