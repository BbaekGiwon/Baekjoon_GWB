#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	while(1) {
		int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr+3);
		if(arr[2]==0) {
			return 0;
		}
		
		if(arr[0]+arr[1]>arr[2]) {
			if(arr[0]!=arr[1]&&arr[1]!=arr[2]&&arr[2]!=arr[0]) {
				cout << "Scalene\n";
			}
			else {
				if(arr[0]==arr[1]&&arr[1]==arr[2]&&arr[2]==arr[0]) {
					cout << "Equilateral\n";
				}
				else {
					cout << "Isosceles\n";
				}
			}
		}
		else {
			cout << "Invalid\n";
		}
	}
	
	
	
	return 0;
}
