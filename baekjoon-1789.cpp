#include <iostream>

using namespace std;

int main(void) {
	long long n, sum=0, i=1;
	cin >> n;
	
	while(1) {
		sum+=i++;
		if(sum>n) break;
	}
	
	cout << i-2;
	return 0;
}
