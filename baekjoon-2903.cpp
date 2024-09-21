#include <iostream>

using namespace std;

int main(void) {
	int n, result=1;
	cin >> n;
	for(int i=0; i<n; i++) {
		result*=2;
	}
	cout << (result+1)*(result+1);
//	1->2 2->3 4->5 8->9
	
	return 0;
}
