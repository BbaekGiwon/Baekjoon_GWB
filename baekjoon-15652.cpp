#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = {0, };
bool visited[MAX] = {0, };

void dfs(int cnt, int num) {
	if(cnt==m) {
		for(int i=0; i<m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for(int i=num; i<=n; i++) {
		if(!visited[i]) {
			if(cnt==m-1) visited[i] = true;
			arr[cnt] = i;
			dfs(cnt+1, i);
			visited[i] = false;
		}
	}
}

int main(void) {
	cin>>n>>m;
	
	dfs(0,1);
}
