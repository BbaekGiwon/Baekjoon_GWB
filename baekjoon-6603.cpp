#include <iostream>

using namespace std;

int k;
int output[6];

void print() {
	for(int i=0; i<6; i++) {
		cout << output[i] << " ";
	}
	cout << "\n";
}

void dfs(int cnt, int num, int *arr, int *visited) {
	if(cnt==6) {
		print();
		return;
	}
	
	for(int i=num; i<k; i++) {
		if(!visited[i]) {
			output[cnt]=arr[i];
			visited[i]++;
			dfs(cnt+1, i+1, arr, visited);
			visited[i]=0;
		}
		
		
	}
}

int main(void) {
	while(1) {
		cin >> k;
		if(k==0) return 0;
		
		int arr[k];
		int visited[k]={0,};
		for(int i=0; i<k; i++) {
			cin >> arr[i];
		}
		
		dfs(0, 0, arr, visited);
		
		cout << "\n";
	}
	return 0;
}
