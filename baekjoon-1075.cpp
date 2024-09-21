#include <iostream>

using namespace std;

int main(void) {
	long long n, f, i;
	cin >> n >> f;
	
	n=n/100*100;
	
	for(i=0; i<=f; i++) {
		if((n+i)%f==0) {
			break;
		}
	}
	
	if(i/10==0) {
		cout << "0" << i;
	}
	else {
		cout << i;
	}
	
	
	
	return 0;
}
