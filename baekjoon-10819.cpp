#include <iostream>

using namespace std;

int n, mmaaxx=0, sum=0;
int arr[8]={0,};
int temp[8]={0,};
int visited[8]={0,};

void dfs(int cnt) {
	if(cnt==n) {
		mmaaxx = max(mmaaxx, sum);
		return;
	}
	
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			visited[i]++;
			temp[cnt]=arr[i];
			if(cnt>0) {
				sum+=abs(temp[cnt-1]-temp[cnt]);
			}
			
			dfs(cnt+1);
						
			visited[i]=0;
			if(cnt>0) {
				sum-=abs(temp[cnt-1]-temp[cnt]);
			}
			temp[cnt]=0;
		}
	}
}

int main(void) {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	dfs(0);
	
	cout << mmaaxx;	
	
	return 0;
}
