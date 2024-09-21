#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int a[3], d[3];
	for(int i=0; i<3; i++) {
		cin >> a[i];
	}
	for(int i=0; i<3; i++) {
		cin >> d[i];
	}
	
	for(int i=-999; i<1000; i++) {
		for(int j=-999; j<1000; j++) {
			if(a[0]*i+a[1]*j ==a[2]) {
				if(d[0]*i+d[1]*j ==d[2]) {
					cout << i << " " << j;
				}
			}
		}
	}
	return 0;
}
