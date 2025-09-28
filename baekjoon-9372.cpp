#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int n, m;
		cin >> n >> m;
		
		int a, b;
		for(int j=0; j<m; j++) {
			cin >> a >> b;
		}
				
		cout << n-1 << "\n";
	}
	
	return 0;
}
