#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int input[100001]={0,};

int binary_search (int temp, int left, int right) {
	int pivot=(left+right)/2;
	
	if(input[pivot]==temp) {
		return 1;
	}
	else if(left>=right) {
		return 0;
	}
	
	if(input[pivot]>temp) {
		return binary_search(temp, left, pivot-1);
	}
	else {
		return binary_search(temp, pivot+1, right);
	}
	
}

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> input[i];
	}
	
	sort(input, input+n);
	
	cin >> m;
	for(int i=0; i<m; i++) {
		int temp;
		cin >> temp;
		cout << binary_search(temp, 0, n-1) << "\n";
	}
	
	return 0;
}
