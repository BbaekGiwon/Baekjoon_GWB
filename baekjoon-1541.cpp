#include <iostream>

using namespace std;

int main(void) {
	int flag=0, sut, sum=0;
	char yeon;
	while(1) {
		cin >> sut;
		
		if(flag==1) sum-=sut;
		else sum+=sut;
		
		cin.get(yeon);
		if(yeon=='\n') break;
		
		if(yeon=='-') flag=1;
	}
	
	cout << sum;
	
	return 0;
}
