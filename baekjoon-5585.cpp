#include <iostream>

using namespace std;

int main(void) {
	int n, sum=0;
	cin >> n;
	n = 1000-n;
	sum+=n/500;
	n%=500;
	sum+=n/100;
	n%=100;
	sum+=n/50;
	n%=50;
	sum+=n/10;
	n%=10;
	sum+=n/5;
	n%=5;
	sum+=n;
	cout << sum;
	
	
	
	
	return 0;
}
