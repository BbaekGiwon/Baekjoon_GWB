#include <iostream> 

using namespace std;

long long facto(long long n) {
	if(n<=2) {
		return n;
	}
	else {
		return n * facto(n-1);
	}
}

int main(void) {
	long long n;
	cin >> n;
	if(n==0) {
		cout << 1;
	}
	else {
		cout << facto(n);
	}

	
	
	return 0;
}
