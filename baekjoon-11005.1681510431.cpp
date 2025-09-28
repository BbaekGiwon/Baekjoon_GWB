#include <iostream>

using namespace std;

int main(void) {
	int n, b, j=1;
	cin >> n >> b;
	while(1) {
		if(n/j==0) {
			break;
		}
		j*=b;
	}
	j/=b;
	
	for(;j>=1; j/=b) {
		if(n/j>=10) {
			char a='A'+n/j-10;
			cout << a;
		}
		else {
			cout << n/j;
		}
		n%=j;
	}
	
	
	
	
	return 0;
}
