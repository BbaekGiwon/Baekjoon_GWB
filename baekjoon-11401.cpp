#include <iostream>
#define MAX 4000000
using namespace std;

long long binary(int n, int k) {
	if(n==1||k==n||k==0) {
		return 1;
	}
	else if(k==n-1||k==1) {
		return n;
	}
	else {
		return ((n-k+1)*binary(n,k-1)/k)%1000000007;
	}
}

int main(void) {
	int n, k;
	cin >> n >> k;
	if(k>n/2) k=n-k;
	
	cout << binary(n,k);
	
	return 0;
}
