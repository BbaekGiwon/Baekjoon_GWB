#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int i, int j) {
	return i>j;
}

int main(void) {
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	for(int i=0; i<n; i++) {
		cin >> b[i];
	}
	
	sort(a, a+n, cmp);
	sort(&b[0], &b[n]);
	
	int sum=0;
	for(int i=0; i<n; i++) {
		sum+=a[i]*b[i];
	}
	
	cout << sum;
	
	
	return 0;
}
