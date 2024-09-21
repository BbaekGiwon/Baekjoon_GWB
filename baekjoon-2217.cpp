#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, max_w=-1;
	cin >> n;
	int rope[n];
	for(int i=0; i<n; i++) {
		cin >> rope[i];
	}
	
	sort(rope, rope+n);
	for(int i=0; i<n; i++) {
		max_w=max(rope[i]*(n-i), max_w);
	}
	
	cout << max_w;
	
	return 0;
}
