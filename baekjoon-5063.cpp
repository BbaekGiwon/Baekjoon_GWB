#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int r, e, c;
		cin >> r >> e >> c;
		if(r<(e-c)) cout << "advertise\n";
		else if(r==(e-c)) cout << "does not matter\n";
		else cout << "do not advertise\n";
	}
	
	return 0;
}
