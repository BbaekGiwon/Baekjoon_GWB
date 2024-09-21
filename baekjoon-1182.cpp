#include <iostream>

using namespace std;

int n,s,is_s=0,count=0;;
int arr[21]={0,};
int visited[21]={0,};

void dfs(int cnt, int num) {
	if(cnt==n) {
		return;
	}
	
	for(int i=num; i<n; i++) {
		if(!visited[i]) {
			visited[i]++;
			is_s+=arr[i];
			if(is_s==s) {
				count++;
			}
			dfs(cnt+1, i+1);
			is_s-=arr[i];
			visited[i]=0;
		}
	}
}


int main(void) {
	cin >> n >> s;
	
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	dfs(0,0);
	
	cout << count;
	
	return 0;
}
