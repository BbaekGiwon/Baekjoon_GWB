#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	long long n, m;
	cin >> n >> m;
	long long tree[n];
	for(int i=0; i<n; i++) {
		cin >> tree[i];
	}
	
	sort(tree, tree+n);
	
	long long left=0, right=tree[n-1], max_height=0;
	
	while(1) {
		if(left>right) break;
		
		long long pivot=(left+right)/2;
		long long sum=0;
		
		for(int i=0; i<n; i++) {
			if(pivot<tree[i]) {
				sum+=tree[i]-pivot;
			}
		}
		
		if(sum<m) {
			right=pivot-1;
		}
		else {
			if(sum>=m) {
				max_height=max(max_height, pivot);
			}
			left=pivot+1;
		}
	}
	
	cout << max_height;
	
	
	return 0;
}
