#include <iostream>

using namespace std;

int main(void) {
	int a, b, c, div=1000000000, num[10]={0,};
	cin >> a >> b >> c;
	a=a*b*c;
	while(a/div==0) div/=10;
	
	while(div>=1) {
		num[a/div]++;
		a%=div;
		div/=10;
	}
	
	for(int i=0; i<10; i++) {
		cout << num[i] << "\n";
	}
	
	
	return 0;
} 
