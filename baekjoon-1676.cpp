#include <iostream>

using namespace std;

int main(void) {
	int n, result=0;
	
	cin >> n;
	
	result+=n/5;
	result+=n/25;
	result+=n/125;
	
	cout << result <<endl;
}
