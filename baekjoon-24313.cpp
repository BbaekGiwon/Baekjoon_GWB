#include <iostream>

using namespace std;

int main(void) {
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;
	
	if(a1<=c) {
		if(a1*n0+a0<=c*n0) {
			cout << "1";
			return 0;
		}
	}
	
	cout << "0";
	
	
	
	
	return 0;
}
