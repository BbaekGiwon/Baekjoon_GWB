#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
	double n;
	cin >> n;
	if(n==0) {
		cout << 0;
		return 0;
	}
	int arr[(int)n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	sort(arr,arr+(int)n);
	
	int cut=(int)floor(n*0.15+0.5);
	double sum=0;
	
	for(int i=cut; i<n-cut; i++) {
		sum+=arr[i];
	}
	
	cout << (int)(floor(sum/(n-cut*2)+0.5));
	
	return 0;
}
