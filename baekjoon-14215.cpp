#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr+3);
	
	if(arr[0]+arr[1]<=arr[2]) {
		cout << (arr[0]+arr[1])*2-1;
	}
	else {
		cout << arr[0]+arr[1]+arr[2];
	}
	
	
	return 0;
}
