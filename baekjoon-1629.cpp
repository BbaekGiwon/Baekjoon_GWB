#include <iostream>

using namespace std;

long long gop(long long a, long long b, long long c) {
	if(b==0) return 1;
	else if(b==1) return a;
	else {
		if(b%2==1) {
			return gop(a, b/2, c)%c * gop(a, b/2+1, c)%c;
		}
		else {
			return gop(a, b/2, c)%c * gop(a, b/2, c)%c;
		}
	}
}

int main(void) {
	long long a, b, c;
	cin >> a >> b >> c;
	
	cout << gop(a, b, c)%c;
	
	
	
	
	return 0;
}
