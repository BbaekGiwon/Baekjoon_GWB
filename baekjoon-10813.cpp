#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	int arr[n+1]={0,};
	for(int i=1; i<=n; i++) {
		arr[i]=i;
	}
	
	for(int a=0; a<m; a++) {
		int i, j;
		cin >> i >> j;
		swap(arr[i],arr[j]);
	}
	
	for(int i=1; i<=n; i++) {
		cout << arr[i] << " ";
	}
	
	
	return 0;
}
