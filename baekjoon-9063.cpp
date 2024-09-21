#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, x_min=10000, x_max=-10000, y_min=10000, y_max=-10000;
	cin >> n;
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		x_min = min(x_min, x);
		x_max = max(x_max, x);
		y_min = min(y_min, y);
		y_max = max(y_max, y);
	}
	
	cout << (x_max-x_min)*(y_max-y_min);
	
	
	return 0;
}
