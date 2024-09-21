#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int n, maax=0, miin=100;
		cin >> n;
		for(int j=0; j<n; j++) {
			int temp;
			cin >> temp;
			maax = max(temp, maax);
			miin = min(temp, miin);
		}
		cout << (maax-miin)*2 << "\n";
	}
	
	
	
	
	return 0;
}
