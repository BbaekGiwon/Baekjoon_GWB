#include <iostream>
#include <algorithm>

using namespace std;

long long ucld_hoze(long long a, long long b) {
	if(b>a) swap(a,b);
	
	if(a%b==0) return b;
	else return ucld_hoze(a%b, b);
}

int main(void) {
	long long a, b;
	cin >> a >> b;
	
	int temp=ucld_hoze(a,b);
	
	cout << a*(b/temp);
	
	
	
	return 0;
}
