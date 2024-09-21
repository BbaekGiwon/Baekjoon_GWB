#include <iostream>
#include <cmath>

using namespace std;

bool Is_prime(long long n) {
	for(long long i=2; i<=sqrt(n); i++) {
		if(n%i==0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		long long n;
		cin >> n;
		if(n==0) n=2;
		else if(n==1) n=2;
		while(Is_prime(n)!=true) {
			n++;
		}
		cout << n << endl;
	}

	
	
	
	return 0;
} 
