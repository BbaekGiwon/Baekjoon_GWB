#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int temp[101]={0,};

void reverse(int *arr, int i, int j) {
	for(int k=0; k<=j-i; k++) {
		temp[j-k]=arr[i+k];
	}
	
	for(int k=i; k<=j; k++) {
		arr[k]=temp[k];
	}
}

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
		reverse(arr, i, j);
	}
	
	for(int i=1; i<=n; i++) {
		cout << arr[i] << " ";
	}
	
	
	
	return 0;
}
