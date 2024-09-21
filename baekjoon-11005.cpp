#include <iostream>

using namespace std;

int main(void) {
	long long n, b, j=1;
	cin >> n >> b;
	
	while(1) {
		j*=b;
		if(n/j==0) {
			break;
		}
	}
	j/=b;
	
	for(;j>=1; j/=b) {
		if(n/j>=10) {
			char a='A'+n/j-10;
			cout << a;
		}
		else {
			char a='0'+n/j;
			cout << a;
		}
		n%=j;
	}
	
	
	
	
	return 0;
}
