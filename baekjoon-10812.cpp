#include <iostream>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	int arr[n+1]={0,};
	for(int i=1; i<=n; i++) {
		arr[i]=i;
	}
	
	for(int a=0; a<m; a++) {
		int i,j,k;
		cin >>i>>j>>k;
		int temp[j-i];
		for(int b=0; b<=j-k; b++) {
			temp[b]=arr[k+b];
		}
		for(int b=j-k+1; b<j-i+1; b++) {
			temp[b]=arr[i-j+k-1+b];
		}
		for(int b=0; b<=j-i; b++) {
			arr[i+b]=temp[b];
		}
	}
	
	for(int i=1; i<=n; i++) {
		cout << arr[i] << " ";
	}
	
	return 0;
}
